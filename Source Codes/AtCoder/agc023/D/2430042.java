import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int s = in.nextInt();
        int[] x = new int[n];
        long[] cnt = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            cnt[i] = in.nextInt();
        }
        if (s >= x[n - 1]) {
            out.println(s - x[0]);
            return;
        }
        if (s <= x[0]) {
            out.println(x[n - 1] - s);
            return;
        }
        long res = x[n - 1] - x[0];
        int left = 0, right = n - 1;
        int end = n - 1;
        if (cnt[left] >= cnt[right]) {
            end = 0;
        }
        while (true) {
            if (x[right] < s || x[left] > s) {
                res += Math.abs(s - x[end]);
                break;
            }
            int nextEnd = -1;
            if (cnt[left] >= cnt[right]) {
                nextEnd = left;
                cnt[left] += cnt[right];
                right--;
            } else {
                nextEnd = right;
                cnt[right] += cnt[left];
                left++;
            }
            res += Math.abs(x[end] - x[nextEnd]);
            end = nextEnd;
        }
        out.println(res);
    }

    void solve123() {
        int n = in.nextInt();
        int s = in.nextInt();
        int[] x = new int[n];
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            x[i ]= in.nextInt();
            cnt[i] = in.nextInt();
        }
        long res = 0;
        while (true) {
            long sum = 0;
            int pos = 0;
            for (int i = 0; i < n; i++) {
                sum += cnt[i];
                if (s >= x[i]) {
                    pos = i;
                }
            }
            if (sum == 0) {
                break;
            }
            long curSum = 0;
            int bestPos = 0;
            for (int right = pos + 1; right < n; right++) {
                if (cnt[right] > sum - curSum) {
                    bestPos = right;
                }
                curSum += cnt[right];
            }
            curSum = 0;
            for (int left = pos; left >= 0; left--) {
                if (cnt[left] != 0 && cnt[left] >= sum - curSum) {
                    bestPos = left;
                }
                curSum += cnt[left];
            }
            res += Math.abs(x[bestPos] - s);
            if (bestPos > pos) {
                for (int i = pos + 1; i <= bestPos; i++) {
                    cnt[i] = 0;
                }
            } else {
                for (int i = pos; i >= bestPos; i--) {
                    cnt[i] = 0;
                }
            }
            s = x[bestPos];
        }
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}