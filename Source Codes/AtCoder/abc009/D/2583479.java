import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int k, m;
    long[] as, cs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        k = sc.nextInt();
        m = sc.nextInt();
        as = new long[k];
        for (int i = k - 1; i >= 0; i--) {
            as[i] = sc.nextLong();
        }
        cs = new long[k];
        for (int i = 0; i < k; i++) {
            cs[i] = sc.nextLong();
        }
        solve();
    }

    void solve() {
        if (m <= k) {
            System.out.println(as[k - m]);
            return;
        }
        long[][][] doubling = new long[31][k][k];
        for (int i = 0; i < k; i++) {
            doubling[0][0][i] = cs[i];
        }
        for (int i = 1; i < k; i++) {
            doubling[0][i][i - 1] = (1L << 32) - 1;
        }
        for (int i = 1; i < 31; i++) {
            doubling[i] = multiplyMatrices(doubling[i - 1], doubling[i - 1]);
        }
        m -= k;
        System.out.println(multiply(dfs(m, doubling), as)[0]);
;   }

    long[][] dfs(int n, long[][][] doubling) {
        if (n == 0) {
            long[][] id = new long[doubling[0].length][doubling[0][0].length];
            for (int i = 0; i < id.length; i++) {
                id[i][i] = (1L << 32) - 1;
            }
            return id;
        }
        if (n == 1) {
            return doubling[0];
        }
        int l = 1;
        int power = 0;
        while (l <= n) {
            l *= 2;
            power++;
        }
        return multiplyMatrices(doubling[--power], dfs(n - l / 2, doubling));
    }

    long[][] multiplyMatrices(long[][] a, long[][] b) {
        long[][] c = new long[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                for (int k = 0; k < a.length; k++) {
                    c[i][j] ^= a[i][k] & b[k][j];
                }
            }
        }
        return c;
    }

    long[] multiply(long[][] a, long[] v) {
        long[] v2 = new long[v.length];
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < v.length; j++) {
                v2[i] ^= a[i][j] & v[j];
            }
        }
        return v2;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}