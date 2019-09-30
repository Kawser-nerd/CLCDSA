import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int x, k, q;
    int[] rs, ts, as;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        x = sc.nextInt();
        k = sc.nextInt();
        rs = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            rs[i] = sc.nextInt();
        }
        q = sc.nextInt();
        ts = new int[q];
        as = new int[q];
        for (int i = 0; i < q; i++) {
            ts[i] = sc.nextInt();
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        int[] hi = new int[k + 1];
        int[] ub = new int[k + 1];
        int[] lo = new int[k + 1];
        int[] lb = new int[k + 1];
        hi[0] = x;
        ub[0] = x;
        for (int i = 1; i <= k; i++) {
            int dt = rs[i] - rs[i - 1];
            if (i % 2 == 1) {
                hi[i] = hi[i - 1] - dt;
                ub[i] = ub[i - 1];
                lo[i] = lo[i - 1] - dt;
                lb[i] = lb[i - 1] + Math.max(0, -lo[i]);
                hi[i] = Math.max(hi[i], 0);
                lo[i] = Math.max(lo[i], 0);
                lb[i] = Math.min(lb[i], x);
            } else {
                hi[i] = hi[i - 1] + dt;
                ub[i] = ub[i - 1] - Math.max(0, hi[i] - x);
                lo[i] = lo[i - 1] + dt;
                lb[i] = lb[i - 1];
                hi[i] = Math.min(hi[i], x);
                ub[i] = Math.max(ub[i], 0);
                lo[i] = Math.min(lo[i], x);
            }
        }
        int l = 0;
        int ans;
        for (int i = 0; i < q; i++) {
            l = upper_bound(rs, ts[i]);
            int dt = ts[i] - rs[l - 1];
            if (as[i] <= lb[l - 1]) {
                ans = lo[l - 1];
            } else if (as[i] >= ub[l - 1]) {
                ans = hi[l - 1];
            } else {
                ans = (as[i] - lb[l - 1]) + lo[l - 1];
            }
            if (l % 2 == 1) {
                ans = Math.max(0, ans - dt);
            } else {
                ans = Math.min(x, ans + dt);
            }
            System.out.println(ans);
        }
    }

    static int upper_bound(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while (high - low >= 0) {
            int mid = (low + high) / 2;
            if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
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