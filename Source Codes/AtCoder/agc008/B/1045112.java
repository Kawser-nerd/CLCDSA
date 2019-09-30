import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        T solver = new T();
        solver.solve(1, in, out);
        out.close();
    }

    static class T {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n  = in.nextInt(), k = in.nextInt();
            final int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
            }
            final long[] prefSum = new long[n];
            final long[] posSum = new long[n];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    prefSum[i] = arr[i];
                    if (arr[i] > 0)
                        posSum[i] = arr[i];
                } else {
                    prefSum[i] = prefSum[i - 1] + arr[i];
                    posSum[i] = posSum[i - 1] + (arr[i] > 0 ? arr[i] : 0);
                }
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                int j = i + k - 1;
                if (j >= n) break;
                long as = rangeSum(0, i - 1, posSum) + rangeSum(j + 1, n - 1, posSum);
                as = Math.max(as, as + rangeSum(i, j, prefSum));
                ans = Math.max(ans, as);
            }
            out.println(ans);

        }

        private long rangeSum(int i, int j, long[] posSum) {
            if (j < i) return 0;
            if (i == 0) return posSum[j];
            return posSum[j] - posSum[i - 1];
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}