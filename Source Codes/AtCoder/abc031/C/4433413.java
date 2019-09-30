import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {
        int[] a;

        int partialSum(int start, int end, boolean odd) {
            int sum = 0;
            for (int i = odd ? start : start + 1; i <= end; i += 2) {
                sum += a[i];
            }
            return sum;
        }

        void solve(InputReader in, PrintWriter out) {
            int N = in.nextInt();
            a = in.nextIntArray(N);

            int ans = Integer.MIN_VALUE;
            for (int takSign = 0; takSign < N; ++takSign) {
                int aoIndex = 0; int aoSumMax = Integer.MIN_VALUE;
                for (int aoSign = 0; aoSign < N; ++aoSign) {
                    if (takSign == aoSign) continue;
                    int aoSum = partialSum(Math.min(takSign, aoSign), Math.max(takSign, aoSign), false);
                    if (aoSum > aoSumMax) {
                        aoIndex = aoSign;
                        aoSumMax = aoSum;
                    }
                }
                int candidate = partialSum(Math.min(takSign, aoIndex), Math.max(takSign, aoIndex), true);
                ans = Math.max(ans, candidate);
            }

            out.println(ans);
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) arr[i] = this.nextInt();
            return arr;
        }
    }
}