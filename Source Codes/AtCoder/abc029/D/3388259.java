import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int N;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        System.out.println(solve());
    }

    static int solve() {
        int[] nums = toNumbers(N);

        return dfs(nums, 0, true).ones;
    }

    static Ret dfs(int[] nums, int k, boolean tight) {
        if( k == nums.length ) {
            return new Ret(1, 0);
        }

        int n = nums[k];
        if( tight ) {
            if( n == 0 ) {
                return dfs(nums, k + 1, true);

            } else if( n == 1 ) {
                Ret a = dfs(nums, k + 1, true).one();
                Ret b = dfs(nums, k + 1, false);
                return new Ret(a.times + b.times, a.ones + b.ones);

            } else {
                Ret a = dfs(nums, k+1, true);
                Ret b = dfs(nums, k+1, false).mul(n-1);
                Ret c = dfs(nums, k+1, false).one();
                return new Ret(a.times + b.times + c.times, a.ones + b.ones + c.ones);
            }

        } else {
            Ret a = dfs(nums, k+1, false).mul(9);
            Ret b = dfs(nums, k+1, false).one();
            return new Ret(a.times + b.times, a.ones + b.ones);
        }
    }

    static class Ret {
        int times;
        int ones;

        public Ret(int times, int ones) {
            this.times = times;
            this.ones = ones;
        }

        public Ret mul(int n) {
            return new Ret(n*times, n*ones);
        }

        public Ret one() {
            return new Ret(times, ones + times);
        }
    }

    static int[] toNumbers(long n) {
        String s = String.valueOf(n);
        char[] chars = s.toCharArray();
        int[] nums = new int[chars.length];
        for (int i = 0; i < chars.length; i++) {
            nums[i] = chars[i] - '0';
        }
        return nums;
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}