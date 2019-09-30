
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class E {

    private int solveTest() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[][] a = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt();
            }
        }
        int[][] b = new int[n][];
        int[][] c = new int[n][];
        int bn = 0;
        int cn = 0;
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][0] < 0 && a[i][1] > 0) {
                b[bn++] = a[i];
            }
            if (a[i][0] > 0 && a[i][1] < 0) {
                c[cn++] = a[i];
            }
            if (a[i][0] >= 0 && a[i][1] >= 0) {
                add += a[i][0] + a[i][1];
            }
        }
        Arrays.sort(b, 0, bn, new Comparator<int[]>() {
            @Override
            public int compare(int[] x, int[] y) {
                return Integer.compare(x[0] + x[1], y[0] + y[1]);
            }
        });
        Arrays.sort(c, 0, cn, new Comparator<int[]>() {
            @Override
            public int compare(int[] x, int[] y) {
                return Integer.compare(x[0] + x[1], y[0] + y[1]);
            }
        });
        int[][] db = new int[bn + 1][cn + 1];
        int[][] dc = new int[bn + 1][cn + 1];
        for (int[] ints : dc) {
            Arrays.fill(ints, -1000000000);
        }
        for (int[] ints : db) {
            Arrays.fill(ints, -1000000000);
        }
        db[0][0] = 0;
        dc[0][0] = 0;
        int res = 0;
        for (int i = 0; i <= bn; i++) {
            for (int j = 0; j <= cn; j++) {
//                System.out.println(i + " " + j + " " + db[i][j] + " " + dc[i][j]);
                int[] s = new int[2];
                for (int ii = i; ii < bn; ii++) {
                    s[0] += b[ii][0];
                    s[1] += b[ii][1];
                    if (dc[i][j] + s[0] < 0) {
                        db[ii + 1][j] = Math.max(db[ii + 1][j], s[1]);
                    }
                }
                if (j == cn) {
                    res = Math.max(res, Math.max(dc[i][j] + s[0], 0) + s[1]);
//                    System.out.println(i + " " + j + " " + res);
                }
                s = new int[2];
                for (int jj = j; jj < cn; jj++) {
                    s[0] += c[jj][0];
                    s[1] += c[jj][1];
                    if (db[i][j] + s[1] < 0) {
                        dc[i][jj + 1] = Math.max(dc[i][jj + 1], s[0]);
                    }
                }
                if (i == bn) {
                    res = Math.max(res, s[0] + Math.max(db[i][j] + s[1], 0));
//                    System.out.println(i + " " + j + " " + res);
                }
            }
        }
        return res + add;
    }

    private void apply(int[] cur, int[] a) {
        for (int i = 0; i < cur.length; i++) {
            cur[i] = Math.max(cur[i] + a[i], 0);
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            int res = solveTest();
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
        new E().run();
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