import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    long[] as;
    long sum;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        as = new long[n];
        sum = 0;
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextLong();
            sum += as[i];
        }
        solve();
    }

    void solve() {
        if (check(as)) {
            System.out.println(0);
            return;
        }
        long count = 0;
        while (true) {
            long tempCount = 0;
            boolean flag = true;
            long[] memo = new long[n];
            for (int i = 0; i < n; i++) {
                memo[i] = as[i] / n;
                tempCount += memo[i];
                as[i] %= n;
            }
            count += tempCount;
            long max = Long.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                as[i] += tempCount - memo[i];
                if (as[i] > max) {
                    max = as[i];
                }
            }
            if (max < n) {
                break;
            }
        }
        System.out.println(count);
    }

    boolean check (long[] as) {
        boolean flag = true;
        for (int i = 0; i < as.length; i++) {
            if (as[i] >= as.length) {
                flag = false;
                break;
            }
        }
        return flag;
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