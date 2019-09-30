import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n, l, q;
    int[] xs, as, bs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        xs = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextInt();
        }
        l = sc.nextInt();
        q = sc.nextInt();
        as = new int[q];
        bs = new int[q];
        for (int i = 0; i < q; i++) {
            as[i] = sc.nextInt() - 1;
            bs[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        int logN = (int)(9 / Math.log(2)) + 1;
        int[][] doubling = new int[n][logN];
        for (int i = 0; i < n; i++) {
            doubling[i][0] = upper_bound(xs, xs[i] + l) - 1;
        }
        for (int i = 1; i < logN; i++) {
            for (int j = 0; j < n; j++) {
                doubling[j][i] = doubling[doubling[j][i - 1]][i - 1];
            }
        }
        for (int i = 0; i < q; i++) {
            int a = as[i];
            int b = bs[i];
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            int ans = 0;

            /*
            int prevHotel = -1;
            outer:
            while (a < b) {
                for (int j = 0; j < logN; j++) {
                    if (doubling[a][j] >= b) {
                        if (prevHotel > 0) {
                            a = prevHotel;
                            ans += pow(2, j - 1);
                            prevHotel = -1;
                            j = -1;
                        } else {
                            ans += pow(2, j);
                            break outer;
                        }
                    } else {
                        prevHotel = doubling[a][j];
                    }
                }
            }
                */
            while (a < b) {
                int next = lower_bound(doubling[a], b);
                //System.out.println(a + " " + b + " " + next + " " + doubling[a][next]);
                if (next == 0) {
                    ans++;
                    break;
                }
                ans += pow(2, next - 1);
                a = doubling[a][next - 1];
            }
            System.out.println(ans);
        }
    }

    long pow(long x, int n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x;
            }
            x = x * x;
            n >>= 1;
        }
        return ans;
    }

    static int lower_bound(int[] arr, int key) {
        return lower_bound(arr, 0, arr.length - 1, key);
    }

    static int lower_bound(int[] arr, int beginIndex, int endIndex, int key) {
        int low = beginIndex;
        int high = endIndex;
        while (high - low >= 0) {
            int mid = (low + high) / 2;
            if (key <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    static int upper_bound(int[] arr, int key) {
        return upper_bound(arr, 0, arr.length - 1, key);
    }

    static int upper_bound(int[] arr, int beginIndex, int endIndex, int key) {
        int low = beginIndex;
        int high = endIndex;
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