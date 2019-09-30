import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long n;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextLong();
        solve();
    }

    void solve() {
        int depth = 0;
        for (long k = n; k > 0; k /= 2) {
            depth++;
        }
        long x = 1;
        int turn = 0;
        boolean even = depth % 2 == 0;
        while (x <= n) {
            if (turn == 0) {
                if (even) {
                    x *= 2;
                } else {
                    x = 2 * x + 1;
                }
            } else {
                if (even) {
                    x = 2 * x + 1;
                } else {
                    x *= 2;
                }
            }
            turn = (turn + 1) % 2;
        }
        if (turn == 0) {
            System.out.println("Takahashi");
        } else {
            System.out.println("Aoki");
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