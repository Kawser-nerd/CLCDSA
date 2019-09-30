import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    int[] ts, vs;
    double[] elapsedTs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        ts = new int[n];
        vs = new int[n];
        for (int i = 0; i < n; i++) {
            ts[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            vs[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        elapsedTs = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            elapsedTs[i] = elapsedTs[i - 1] + ts[i - 1];
        }
        double prevMaximumVelocity = 0.0;
        double area = 0.0;
        for (int i = 1; i <= 2* elapsedTs[n]; i++) {
            double maximumVelocity = maximumVelocity((double)i / 2, elapsedTs[n]);
            area += (maximumVelocity + prevMaximumVelocity) / 4;
            prevMaximumVelocity = maximumVelocity;
        }
        System.out.printf("%4f\n", area);
    }

    double maximumVelocity(double elapsedTime, double totalTime) {
        double[] constraints = new double[n + 2];
        constraints[n] = elapsedTime;
        constraints[n + 1] = totalTime - elapsedTime;
        for (int i = 0; i < n; i++) {
            if (elapsedTime < elapsedTs[i]) {
                constraints[i] = vs[i] + elapsedTs[i] - elapsedTime;
            } else if (elapsedTime > elapsedTs[i + 1]) {
                constraints[i] = vs[i] + elapsedTime - elapsedTs[i + 1];
            } else {
                constraints[i] = vs[i];
            }
        }
        double ret = Double.MAX_VALUE;
        for (int i = 0; i < constraints.length; i++) {
            ret = Math.min(ret, constraints[i]);
        }
        return ret;
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