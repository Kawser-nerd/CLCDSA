import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int a, b, c;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        solve();
    }

    void solve() {
        double low = 0;
        double high = 100;
        int count = 0;
        while (count < 10000) {
            double mid = (low + high) / 2;
            double value = f(mid);
            if (value >= 100) {
                high = mid;
            } else {
                low = mid;
            }
            count++;
        }
        System.out.println(low);
    }

    double f(double t) {
        return a * t + b * Math.sin(c * t * Math.PI);
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