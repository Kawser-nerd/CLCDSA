import java.io.*;
import java.util.*;
import java.util.function.Consumer;

public class Main {

    static MyScanner sc;
    private static PrintWriter out;
    static long M = 1000000007;

    public static void main(String[] s) throws Exception {
        StringBuilder stringBuilder = new StringBuilder();
//        stringBuilder.append("T");
//        for (int i = 0 ; i < 7999  ; i++) {
//            stringBuilder.append("F");
//        }
//        stringBuilder.append(" 0 -7999 ");

        if (stringBuilder.length() == 0) {
            sc = new MyScanner(System.in);
        } else {
            sc = new MyScanner(new BufferedReader(new StringReader(stringBuilder.toString())));
        }


        out = new PrintWriter(new OutputStreamWriter(System.out));
        long t = System.currentTimeMillis();


        solve();
        out.flush();
    }

    private static void solve() {
        String k = sc.next();
        int min = 1;
        int max = k.length() + 1;
        while (min + 1 < max) {
            int m = (max + min) / 2;
            if (v(m, k)) {
                min = m;
            } else {
                max = m;
            }
        }
        out.println(min);
    }


    private static boolean v(int m, String k) {
        boolean rev = false;
        for (int i = 0; i < m ; i++) {
            char l = k.charAt(i);
            boolean o = rev ^ l == '1';
            int left = k.length() - i;
            if (o) {
                if (left < m) return false;
                rev = !rev;
            }
        }
        return true;
    }


    private static int[][] tr(int n, int m) {
        int[][] x = new int[2][m];
        for (int i = 0; i < m; i++) {
            x[0][i] = sc.nextInt() - 1;
            x[1][i] = sc.nextInt() - 1;
        }
        int[][] neig = pn(x, n);
        return neig;
    }

    private static int[][] pn(int[][] x, int n) {
        int[] ct = new int[n];
        int[][] res = new int[n][];
        for (int v : x[0]) {
            ct[v]++;
        }
        for (int v : x[1]) {
            ct[v]++;
        }
        for (int l = 0; l < n; l++) {
            res[l] = new int[ct[l]];
        }
        for (int i = 0; i < x[0].length; i++) {
            res[x[0][i]][--ct[x[0][i]]] = x[1][i];
            res[x[1][i]][--ct[x[1][i]]] = x[0][i];
        }
        return res;
    }


    private static void solveT() {
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }

    private static long gcd(long l, long l1) {
        if (l > l1) return gcd(l1, l);
        if (l == 0) return l1;
        return gcd(l1 % l, l);
    }

    private static long pow(long a, long b, long m) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long pp = pow(a, b / 2, m);
        pp *= pp;
        pp %= m;
        return (pp * (b % 2 == 0 ? 1 : a)) % m;
    }


    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        MyScanner(BufferedReader br) {
            this.br = br;
        }

        public MyScanner(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        String next() {
            findToken();
            return st.nextToken();
        }

        int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextInt();
            }
            return k;
        }

        long[] nl(int n) {
            long[] k = new long[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextLong();
            }
            return k;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }


}