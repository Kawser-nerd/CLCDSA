
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

    private char[][] a;
    private int n;
    private int m;

    private String solveTest() throws IOException {
        n = nextInt();
        m = nextInt();
        int D = nextInt();
        a = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        int[] qx = new int[n * m];
        int[] qy = new int[n * m];
        int[][] d = new int[n][m];
        int[][] pd = new int[n][m];
        for (int[] ints : d) {
            Arrays.fill(ints, -1);
        }
        int h = 0; int t = 1;
        int tx = -1;
        int ty = -1;
        int sx = -1;
        int sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'S') {
                    qx[0] = i;
                    qy[0] = j;
                    d[i][j] = 0;
                    pd[i][j] = -1;
                    sx = i;
                    sy = j;
                }
                if (a[i][j] == 'F') {
                    tx = i;
                    ty = j;
                }
            }
        }
        int[] dx = new int[]{-1, 1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};
        while (t > h) {
            int x = qx[h];
            int y = qy[h];
            h++;
            for (int dd = 0; dd < 4; dd++) {
                int xx = x + dx[dd];
                int yy = y + dy[dd];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    if (a[xx][yy] != '#' && d[xx][yy] == -1) {
                        qx[t] = xx;
                        qy[t] = yy;
                        t++;
                        d[xx][yy] = d[x][y] + 1;
                        pd[xx][yy] = dd;
                    }
                }
            }
        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                System.out.print(d[i][j] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println(D + " " + d[tx][ty]);
        if (D > d[tx][ty]) {
            return "IMPOSSIBLE";
        }
        if (D % 2 != d[tx][ty] % 2) {
            return "IMPOSSIBLE";
        }
        if (D < Math.abs(tx - sx) + Math.abs(ty - sy)) {
            return "IMPOSSIBLE";
        }

        int[] std = new int[n * m];
        int ss = 0;

        int x = tx;
        int y = ty;
        int curD = d[tx][ty];
        while (pd[x][y] != -1) {
            int dd = pd[x][y];
            std[ss] = dd;
            ss++;
            x -= dx[dd];
            y -= dy[dd];
        }

        int[] len = new int[n * m];
        int[] dd = new int[n * m];
        int[] next = new int[n * m];
        int[] prev = new int[n * m];

        int nn = 1;
        len[0] = 0;
        dd[0] = -1;

        for (int i = 0; i < ss; i++) {
            if (std[i] == dd[prev[0]]) {
                len[prev[0]]++;
            } else {
                dd[nn] = std[i];
                len[nn] = 1;
                next[prev[0]] = nn;
                prev[nn] = prev[0];
                prev[0] = nn;
                nn++;
            }
        }



        if (curD > D)
        outer:for (int ll = 2; ll < 1000; ll++) {
            for (int i = next[0]; i != 0; i = next[i]) {
                System.out.print(i + "(" + dd[i] + " " + len[i] + " " + prev[i] + ") ");
            }
            System.out.println();
            boolean ok = false;
            while (!ok) {
                ok = true;
                for (int i = next[0]; next[i] != 0; i = next[i]) {
                    if (dd[prev[i]] == (dd[next[i]] ^ 1) && len[i] == ll) {
                        ok = false;
                        int a = prev[i];
                        int b = next[i];
                        len[a]--;
                        if (len[a] == 0) {
                            next[prev[a]] = next[a];
                            prev[next[a]] = prev[a];
                            if (dd[next[prev[a]]] == (dd[prev[a]] ^ 1)) {
                                System.out.println("!!!");
                            }
                        }
                        len[b]--;
                        if (len[b] == 0) {
                            next[prev[b]] = next[b];
                            prev[next[b]] = prev[b];
                        }
                        curD -= 2;
//                        for (int ii = next[0]; ii != 0; ii = next[ii]) {
//                            if (ii == i) System.out.print("+");
//                            System.out.print("(" + dd[ii] + " " + len[ii] + ") ");
//                        }
//                        System.out.println();
                        if (curD == D) break outer;
                    }
                }
                if (!ok) {
//                    for (int i = next[0]; next[i] != 0; i = next[i]) {
//                        while (dd[next[i]] == dd[i]) {
//                            len[i] += len[next[i]];
//                            next[i] = next[next[i]];
//                            prev[next[i]] = i;
//                        }
//                    }
                }
            }
        }

            for (int i = next[0]; i != 0; i = next[i]) {
                System.out.print(i + "(" + dd[i] + " " + len[i] + " " + prev[i] + ") ");
            }
            System.out.println();
        x = tx;
        y = ty;
        for (int i = next[0]; i != 0; i = next[i]) {
            for (int j = 0; j < len[i]; j++) {
                x -= dx[dd[i]];
                y -= dy[dd[i]];
                a[x][y] = 'o';
            }
        }




//


//        for (int i = 0; i < ss; i++) {
//            a[stx[i]][sty[i]] = (char) ('0' + std[i]);
//        }
//        if (D != curD) {
//            System.out.println(D + " " + curD);
//            throw new RuntimeException();
//        }

        StringBuffer map = new StringBuffer();
        for (int i = 0; i < n; i++) {
            map.append("\n").append(new String(a[i]));
        }

        return "POSSIBLE" + map.toString();
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new D().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}