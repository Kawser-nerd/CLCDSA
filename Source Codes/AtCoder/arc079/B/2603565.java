import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long k;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        k = sc.nextLong();
        solve();
    }

    void solve() {
        long n = 50;
        long[] as = new long[(int)n];
        long quotient = k / n;
        long remainder = k % n;
        for (int i = 0; i < n; i++) {
            as[i] = 49 + quotient;
        }
        for (int i = 0; i < remainder; i++) {
            as[i] += n;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                as[j] -= 1;
            }
        }
        System.out.println(n);
        for (int i = 0; i < n; i++) {
            System.out.print(as[i]);
            if (i < n - 1) {
                System.out.print(" ");
            } else {
                System.out.println();
            }
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