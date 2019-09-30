import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long a = in.nextLong();
            long b = in.nextLong();
            while (a > 0 && Long.highestOneBit(a) == Long.highestOneBit(b)) {
                long flip = Long.highestOneBit(a);
                a ^= flip;
                b ^= flip;
            }
            if (b == 0) {
                out.println(1);
                return;
            }
            int first = Long.numberOfTrailingZeros(Long.highestOneBit(b));
            int second;
            if (b == (1L << first)) {
                second = -1;
            } else {
                second = Long.numberOfTrailingZeros(Long.highestOneBit(b ^ (1L << first)));
            }
            long res = b - a + 1;
            res += ((1L << first) + (1L << (second + 1)) - 1 - b);
            if (a == 0 || Long.numberOfTrailingZeros(Long.highestOneBit(a)) <= second) {
                res += (1L << (first + 1)) - ((1L << first) + (1L << (second + 1)));
            } else {
                int middle = Long.numberOfTrailingZeros(Long.highestOneBit(a));
                res += (1L << (first + 1)) - ((1L << first) + (1L << (middle + 1)));
                res += (1L << (middle + 1)) - a;
            }
            out.println(res);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}