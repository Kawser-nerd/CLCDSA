import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int n, m, p, q, r;
    int[] xs, ys, zs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt();
        q = sc.nextInt();
        r = sc.nextInt();
        xs = new int[r];
        ys = new int[r];
        zs = new int[r];
        for (int i = 0; i < r; i++) {
            xs[i] = sc.nextInt() - 1;
            ys[i] = sc.nextInt() - 1;
            zs[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        int max = 0;
        for (int girls = 0; girls < (1 << n); girls++) {
            if (Integer.bitCount(girls) != p) {
                continue;
            }
            int[] boyValues = new int[m];
            for (int i = 0; i < r; i++) {
                int g = 1 << xs[i];
                if ((g & girls) > 0) {
                    boyValues[ys[i]] += zs[i];
                }
            }
            Arrays.sort(boyValues);
            int value = 0;
            for (int i = m - 1; i >= m - q; i--) {
                value += boyValues[i];
            }
            if (max < value) {
                max = value;
            }
        }
        System.out.println(max);
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