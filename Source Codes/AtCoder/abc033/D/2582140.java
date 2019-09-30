import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int n;
    int[] xs, ys;
    double EPS = 1.0e-9;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        xs = new int[n];
        ys = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextInt();
            ys[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        double rightAngle = Math.PI / 2;
        long right = 0;
        long obtuse = 0;
        for (int i = 0; i < n; i++) {
            double[] angles = new double[n - 1];
            int k = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                angles[k++] = Math.atan2(ys[j] - ys[i], xs[j] - xs[i]);
            }
            Arrays.sort(angles);
            double[] anglesLoop = new double[2 * n - 2];
            System.arraycopy(angles, 0, anglesLoop, 0, n - 1);
            System.arraycopy(angles, 0, anglesLoop, n - 1, n - 1);
            for (int j = n - 1; j < 2 * n - 2; j++) {
                anglesLoop[j] += 2 * Math.PI;
            }
            for (int j = 0; j < n - 1; j++) {
                double t1 = angles[j] + Math.PI / 2 - EPS;
                double t2 = angles[j] + Math.PI / 2 + EPS;
                double t3 = angles[j] + Math.PI - EPS;
                int i1 = lower_bound(anglesLoop, j + 1, j + n - 1, t1);
                int i2 = lower_bound(anglesLoop, j + 1, j + n - 1, t2);
                int i3 = lower_bound(anglesLoop, j + 1, j + n - 1, t3);
                right += i2 - i1;
                obtuse += i3 - i2;
            }
        }
        long acute = (long)n * (n - 1) * (n - 2) / 6 - right - obtuse;
        System.out.println(acute + " " + right + " " + obtuse);
    }

    static int lower_bound(double[] arr, double key) {
        return lower_bound(arr, 0, arr.length - 1, key);
    }

    static int lower_bound(double[] arr, int beginIndex, int endIndex, double key) {
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