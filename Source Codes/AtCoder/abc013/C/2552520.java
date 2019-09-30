import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long n, a, b, c, d, e;
    long h;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextLong();
        h = sc.nextLong();
        a = sc.nextLong();
        b = sc.nextLong();
        c = sc.nextLong();
        d = sc.nextLong();
        e = sc.nextLong();
        solve();
    }

    void solve() {
        b += e;
        d += e;
        long diff = n * e - h;
        long ans = Long.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            long tempDiff = diff - i * b;
            long minJ = tempDiff / d + 1;
            if (tempDiff < 0) {
                minJ = 0;
            }
            long tempAns = i * a + minJ * c;
            if (tempAns < ans) {
                ans = tempAns;
            }
        }
        System.out.println(ans);
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