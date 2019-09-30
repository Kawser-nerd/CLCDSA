import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.BitSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        MedianSum solver = new MedianSum();
        solver.solve(1, in, out);
        out.close();
    }

    static class MedianSum {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            int[] A = new int[N];
            int sum = 0;
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
                sum += A[i];
            }

            BitSet bitSet = new BitSet(sum);
            bitSet.set(sum);
            for (int i = 0; i < N; i++) {
                bitSet.or(bitSet.get(A[i], sum + 1));
            }
            out.println(bitSet.nextSetBit((sum + 1) / 2));

//        boolean[][] F = new boolean[N + 1][sum + 1];
//
//        F[0][0] = true;
//        for (int i = 0; i <= N; i++) F[i][0] = true;
//
//
//        for (int i = 1; i <= N; i++) {
//            for (int s = 1; s <= sum; s++) {
//                F[i][s] |= F[i - 1][s];
//                if (s - A[i - 1] >= 0) F[i][s] |= F[i - 1][s - A[i - 1]];
//            }
//        }
//
//        for (int s = (sum + 1) / 2; s <= sum; s++) {
//            if (F[N][s]) {
//                out.println(s);
//                return;
//            }
//        }
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