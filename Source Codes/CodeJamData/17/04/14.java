import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        new Main().go();
    }

    PrintWriter out;
    Reader in;
    BufferedReader br;

    Main() throws IOException {

        try {

            //br = new BufferedReader( new FileReader("input.txt") );
            in = new Reader("D-large.in");
            out = new PrintWriter( new BufferedWriter(new FileWriter("output.txt")) );
        }
        catch (Exception e) {

            //br = new BufferedReader( new InputStreamReader( System.in ) );
            in = new Reader();
            out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );
        }
    }

    int inf = 2000000000;
    int mod = 1000000007;
    double eps = 0.00000001;

    int n;
    int m;

    //ArrayList<Pair>[] g = new ArrayList[2000000];

    int z = 400010;


    void solve() throws IOException {

        int n = in.nextInt();
        int m = in.nextInt();

        int[][] a = new int[n][n];

        int[][] row = new int[4][n];
        int[][] col = new int[4][n];
        int[][] dig = new int[4][5*n];

        ArrayList<Integer>[] g = new ArrayList[n];
        ArrayList<Integer>[] g2 = new ArrayList[2*n+10];

        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();

        for (int i = 0; i < 2*n+10; i++)
            g2[i] = new ArrayList<>();

        int cnt = 0;

        for (int i = 0; i < m; i++) {

            String s = in.next();
            int r = in.nextInt()-1;
            int c = in.nextInt()-1;
            a[r][c] = s.charAt(0);
            if (a[r][c] == '+')
                a[r][c] = 1;
            if (a[r][c] == 'x')
                a[r][c] = 2;
            if (a[r][c] == 'o')
                a[r][c] = 3;

            row[a[r][c]][r]++;
            col[a[r][c]][c]++;
            dig[a[r][c]][r-c+n]++;
            dig[a[r][c]][r+c+2*n]++;
            cnt++;
            if (a[r][c] == 3)
                cnt++;
        }


        TreeSet<Pair> ans = new TreeSet<>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 0)
                    if (dig[1][i-j+n] == 0 && dig[1][i+j+2*n] == 0 && dig[3][i-j+n] == 0 && dig[3][i+j+2*n] == 0)
                        g2[i+j].add(i-j+n);

        Arrays.fill(from, -1);
        Arrays.fill(to, -1);

        for (int i = 0; i < 2*n-1; i++)
            if (to[i] == -1) {
                dfs(i, g2);
                cc++;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (to[i+j] == i-j+n) {
                    a[i][j] = 1;
                    ans.add(new Pair(i, j));
                    row[1][i]++;
                    col[1][j]++;
                    dig[1][i-j+n]++;
                    dig[1][i+j+2*n]++;
                    cnt++;
                }

        for (int i = 0; i < n; i++)
            if (row[2][i] == 0 && row[3][i] == 0)
                for (int j = 0; j < n; j++)
                    if (a[i][j] == 0 && col[2][j] == 0 && col[3][j] == 0)
                        g[i].add(j);

        Arrays.fill(from, -1);
        Arrays.fill(to, -1);

        for (int i = 0; i < n; i++)
            if (to[i] == -1) {
                dfs(i, g);
                cc++;
            }

        for (int i = 0; i < n; i++)
            if (to[i] != -1) {
                a[i][to[i]] = 2;
                ans.add(new Pair(i, to[i]));
                row[2][i]++;
                col[2][to[i]]++;
                dig[2][i-to[i]+n]++;
                dig[2][i+to[i]+2*n]++;
                cnt++;
            }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0 && a[i][j] != 3) {

                    int c1 = 0;
                    int c2 = 0;
                    if (a[i][j] == 1)
                        c1++;

                    if (a[i][j] == 2)
                        c2++;

                    //System.err.println(i+" "+j+" "+(row[2][i]-c2));

                    if (row[2][i]-c2 == 0 && col[2][j]-c2 == 0 && dig[1][i-j+n]-c1 == 0 && dig[1][i+j+2*n]-c1 == 0)
                        if (row[3][i] == 0 && col[3][j] == 0 && dig[3][i-j+n] == 0 && dig[3][i+j+2*n] == 0)
                        {
                            a[i][j] = 3;
                            row[3][i]++;
                            col[3][j]++;
                            dig[3][i-j+n]++;
                            dig[3][i+j+2*n]++;
                            ans.add(new Pair(i, j));
                            cnt++;
                        }
                }
            }
        }

        out.println(cnt + " " + ans.size());
        for (Pair p : ans) {
            out.println((a[p.a][p.b] == 1 ? '+' : a[p.a][p.b] == 2 ? 'x' : 'o')+" "+(p.a+1)+" "+(p.b+1));
        }
    }

    int[] used = new int[500];
    int[] from = new int[500];
    int[] to = new int[500];
    int cc = 1;

    boolean dfs(int v, ArrayList<Integer>[] g) {

        //System.err.println(v);

        if (used[v] == cc)
            return false;

        used[v] = cc;

        for (int u : g[v])
            if (from[u] == -1 || dfs(from[u], g)) {

                from[u] = v;
                to[v] = u;
                return true;
            }

        return false;
    }

    void go() throws IOException {

        int t = in.nextInt();
        int cs = 1;

        while (t > 0) {
            out.print("Case #"+cs+": ");
            solve();
            //out.println();
            cs++;
            t--;
        }

        out.flush();
        out.close();
    }

    class Pair implements Comparable<Pair>{

        int a;
        int b;

        Pair(int a, int b) {

            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {

            if (b > p.b) return 1;
            if (b < p.b) return -1;
            if (a > p.a) return 1;
            if (a < p.a) return -1;
            return 0;
        }
    }

    class Item {

        int a;
        int b;
        int c;

        Item(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }

    class Reader {

        BufferedReader  br;
        StringTokenizer tok;

        Reader(String file) throws IOException {
            br = new BufferedReader( new FileReader(file) );
        }

        Reader() throws IOException {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() throws IOException {

            while (tok == null || !tok.hasMoreElements())
                tok = new StringTokenizer(br.readLine());
            return tok.nextToken();
        }

        int nextInt() throws NumberFormatException, IOException {
            return Integer.valueOf(next());
        }

        long nextLong() throws NumberFormatException, IOException {
            return Long.valueOf(next());
        }

        double nextDouble() throws NumberFormatException, IOException {
            return Double.valueOf(next());
        }


        String nextLine() throws IOException {
            return br.readLine();
        }

    }

}