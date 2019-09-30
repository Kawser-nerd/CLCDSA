import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n;
    int[] as;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        as = new int[3 * n];
        for (int i = 0; i < 3 * n; i++) {
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        PriorityQueue<Integer> former = new PriorityQueue<>();
        PriorityQueue<Integer> latter = new PriorityQueue<>(Collections.reverseOrder());
        long formerSum = 0;
        long latterSum = 0;
        for (int i = 0; i < n; i++) {
            formerSum += (long)as[i];
            former.offer(as[i]);
        }
        for (int i = 2 * n; i < 3 * n; i++) {
            latterSum += (long)as[i];
            latter.offer(as[i]);
        }
        long[] latterSums = new long[n + 1];
        latterSums[n] = latterSum;
        for (int i = 2 * n - 1; i >= n; i--) {
            int max = latter.peek();
            if (max > as[i]) {
                latterSum -= (long)max;
                latterSum += (long)as[i];
                latter.poll();
                latter.offer(as[i]);
            }
            latterSums[i - n] = latterSum;
        }
        long[] formerSums = new long[n + 1];
        formerSums[0] = formerSum;
        for (int i = n; i < 2 * n; i++) {
            int min = former.peek();
            if (min < as[i]) {
                formerSum -= (long)min;
                formerSum += (long)as[i];
                former.poll();
                former.offer(as[i]);
            }
            formerSums[i - n + 1] = formerSum;
        }
        long diff = formerSums[0] - latterSums[0];
        for (int i = 0; i <= n; i++) {
            long tempDiff = formerSums[i] - latterSums[i];
            if (diff < tempDiff) {
                diff = tempDiff;
            }
        }
        System.out.println(diff);
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