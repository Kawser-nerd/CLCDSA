import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int n, k;
    Pair[] beakers;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        k = sc.nextInt();
        beakers = new Pair[n];
        for (int i = 0; i < n; i++) {
            beakers[i] = new Pair(sc.nextInt(), sc.nextInt());
        }
        solve();
    }

    void solve() {
        double low = 0.0;
        double high = 100.0;
        int count = 0;
        while (count < 100) {
            double mid = (low + high) / 2;
            double[] diffs = new double[n];
            for (int i = 0; i < n; i++) {
                diffs[i] = beakers[i].w * (beakers[i].p - mid);
            }
            Arrays.sort(diffs);
            double diff = 0.0;
            for (int i = n - 1; i >= n - k; i--) {
                diff += diffs[i];
            }
            if (diff < 0) {
                high = mid;
            } else {
                low = mid;
            }
            count++;
        }
        System.out.printf("%6f\n", low);
    }

    class Pair implements Comparable<Pair> {
        int w;
        int p;

        Pair(int w, int p) {
            this.w = w;
            this.p = p;
        }

        public int compareTo(Pair p) {
            return this.p - p.p;
        }
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