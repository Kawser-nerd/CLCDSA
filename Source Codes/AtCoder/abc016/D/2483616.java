import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long ax, ay, bx, by;
    int n;
    long[] xs, ys;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        ax = sc.nextLong();
        ay = sc.nextLong();
        bx = sc.nextLong();
        by = sc.nextLong();
        n = sc.nextInt();
        xs = new long[n + 1];
        ys = new long[n + 1];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextLong() - ax;
            ys[i] = sc.nextLong() - ay;
        }
        xs[n] = xs[0];
        ys[n] = ys[0];
        bx -= ax;
        by -= ay;
        ax = 0;
        ay = 0;
        solve();
    }

    void solve() {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            long area11x2 = bx * ys[i] - xs[i] * by;
            long area12x2 = bx * ys[i - 1] - xs[i - 1] * by;
            long area21x2 = -xs[i] * (ys[i - 1] - ys[i]) -
                    (xs[i - 1] - xs[i]) * -ys[i];
            long area22x2 = (bx - xs[i]) * (ys[i - 1] - ys[i]) -
                    (xs[i - 1] - xs[i]) * (by - ys[i]);
            if (area11x2 * area12x2 < 0 && area21x2 * area22x2 < 0) {
                count++;
            }
        }
        System.out.println(count / 2 + 1);
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