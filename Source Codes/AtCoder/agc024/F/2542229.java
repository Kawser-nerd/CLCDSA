import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    String toStr(int mask) {
        return Integer.toBinaryString(mask).substring(1);
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] dp = new int[1 << (n + 1)][];
        for (int rmask = 1; rmask < dp.length; rmask++) {
            int len = n - (32 - Integer.numberOfLeadingZeros(rmask)) + 2;
            dp[rmask] = new int[1 << len];
        }
        for (int i = 0; i <= n; i++) {
            char[] s = in.next().toCharArray();
            for (int mask = 0; mask < s.length; mask++) {
                if (s[mask] == '1') {
                    int set = mask + s.length;
                    dp[1][set]++;
                }
            }
        }
        String ans= "";
        for (int rmask = 1; rmask < dp.length; rmask++) {
            int[] curDp = dp[rmask];
            int sum = 0;
            for (int s : curDp) {
                sum += s;
            }
            if (sum < k) {
                continue;
            }
            String cur = toStr(rmask);
            if (cur.length() > ans.length() || cur.compareTo(ans) < 0) {
                ans= cur;
            }
            for (int curMoreMask = 2; curMoreMask < dp[rmask].length; curMoreMask++) {
                int cnt = curDp[curMoreMask];
                if (cnt == 0) {
                    continue;
                }
                int highestBit = 31 - Integer.numberOfLeadingZeros(curMoreMask);
                int nowBit = (curMoreMask >> (highestBit - 1)) & 1;
                int nextMask = curMoreMask & ((1 << highestBit) - 1);
                nextMask |= (1 << (highestBit - 1));
                int tmp = (rmask << 1) | nowBit;
                dp[tmp][nextMask] += cnt;
                nextMask = getNextNotMask(curMoreMask);
                if (nextMask != -1) {
                    tmp = (rmask << 1) | (1 - nowBit);
                    dp[tmp][nextMask] += cnt;
                }
            }
        }
        out.println(ans);
    }

    int getNextNotMask(int mask) {
        int highestBit = 31 - Integer.numberOfLeadingZeros(mask);
        int needBit = 1 - ((mask >> (highestBit - 1)) & 1);
        for (int bit = highestBit - 2; bit >= 0; bit--) {
            int curBit = (mask >> bit) & 1;
            if (curBit == needBit) {
                return (mask & ((1 << bit) - 1)) | (1 << bit);
            }
        }
        return -1;
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