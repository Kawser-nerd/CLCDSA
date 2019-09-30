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
 *
 * @author kessido
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
            int k = in.NextInt();
            long cur = 1;
            while (k-- != 0) {
                out.println(cur);
                cur = getNext(cur + 1);
            }
        }

        private long getNext(long l) {
            double curVal = getVal(l);
            long best = l;
            for (int i = 0; MathExtentions.power(10, i) - 1 < l; i++) {
                long new_l = l / MathExtentions.power(10, i);
                new_l *= MathExtentions.power(10, i);
                new_l += MathExtentions.power(10, i) - 1;
                double new_v = getVal(new_l);
                if (new_v < curVal) {
                    curVal = new_v;
                    best = new_l;
                }
            }
            return best;
        }

        private double getVal(long o) {
            return ((double) o) / IntegerExtention.sumDigits(o);
        }

    }

    static class MathExtentions {
        public static long power(final long x, final long y) {
            if (y == 0)
                return 1;

            long p = power(x, y / 2);
            p = (p * p);

            if (y % 2 == 0)
                return p;
            else
                return (x * p);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine(), " \t\n\r\f,");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int NextInt() {
            return Integer.parseInt(next());
        }

    }

    static class IntegerExtention {
        public static int sumDigits(long i) {
            if (i == 0) return 0;
            int res = 0;
            do {
                long i1 = i / 10;
                res += i - i1 * 10;
                i = i1;
            } while (i != 0);
            return res;
        }

    }
}