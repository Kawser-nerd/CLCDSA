import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    int h, w, n;
    int[] as, bs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        n = sc.nextInt();
        as = new int[n];
        bs = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt() - 1;
            bs[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        Set<Long> set = new HashSet<>();
        long[] counts = new long[10];
        counts[0] = ((long)h - 2) * (w - 2);
        for (int i = 0; i < n; i++) {
            long key = ((long)as[i] << 32) + bs[i];
            for (int j = -2; j <= 0; j++) {
                for (int k = -2; k <= 0; k++) {
                    if (as[i] + j < 0 || as[i] + j >= h - 2 || bs[i] + k < 0 || bs[i] + k >= w - 2) {
                        continue;
                    }
                    int count = 0;
                    for (int l = 0; l <= 2; l++) {
                        for (int m = 0; m <= 2; m++) {
                            long findKey = ((long) (as[i] + j + l) << 32) + bs[i] + k + m;
                            if (set.contains(findKey)) {
                                count++;
                            }
                        }
                    }
                    counts[count]--;
                    counts[count + 1]++;
                }
            }
            set.add(key);
        }
        for (int i = 0; i < 10; i++) {
            System.out.println(counts[i]);
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