import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static long N;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextLong();

        List<Long> ans = solve();
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(ans.size());
        for (Long l : ans) {
            pw.println(l);
        }
        pw.flush();
    }

    static List<Long> solve() {
        List<Long> ans = new ArrayList<>();
        // ?????????????*9??
        int len = String.valueOf(N).length();

        long min = N - len * 9;
        for (long x = min; x <= N; x++) {
            if( ketawa(x) + x == N ) {
                ans.add(x);
            }
        }
        return ans;
    }

    static int ketawa(long num) {
        int sum = 0;
        String s = String.valueOf(num);
        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
        }
        return sum;
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