import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.InputStreamReader;
import java.util.List;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.LinkedList;
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
        Nondecreasing solver = new Nondecreasing();
        solver.solve(1, in, out);
        out.close();
    }

    static class Nondecreasing {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt();
            long[] A = new long[N];
            int minIdx = 0;
            int maxIdx = 0;
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
                if (A[i] < A[minIdx]) minIdx = i;
                if (A[i] > A[maxIdx]) maxIdx = i;
            }
            List<int[]> moves = new LinkedList<>();
            if (Math.abs(A[maxIdx]) >= Math.abs(A[minIdx])) {
                //all numbers can be made non-negative
                for (int i = 0; i < N; i++) {
                    if (i != maxIdx) {
                        update(A, maxIdx, i, moves);
                    }
                }

                for (int i = 0; i < N - 1; i++) {
                    update(A, i, i + 1, moves);
                }
            } else {
                //all numbers can be made non-positive
                for (int i = 0; i < N; i++) {
                    if (i != minIdx) {
                        update(A, minIdx, i, moves);
                    }
                }

                for (int i = N - 2; i >= 0; i--) {
                    update(A, i + 1, i, moves);
                }
            }

            out.println(moves.size());
            out.println(moves.stream().map(m -> m[0] + " " + m[1]).collect(Collectors.joining("\n")));
        }

        private void update(long[] A, int x, int y, List<int[]> moves) {
            moves.add(new int[]{x + 1, y + 1});
            A[y] += A[x];
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