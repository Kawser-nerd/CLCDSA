import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DASequenceOfPermutations solver = new DASequenceOfPermutations();
        solver.solve(1, in, out);
        out.close();
    }

    static class DASequenceOfPermutations {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] p = in.readIntArray(n);
            int[] q = in.readIntArray(n);
            MiscUtils.decreaseByOne(p, q);
            if (k >= 4) {
                int[] qRev = ArrayUtils.reversePermutation(q);
                int[] pRev = ArrayUtils.reversePermutation(p);
                int[] qRevP = multiplyPermutations(qRev, p);
                int[] pref = multiplyPermutations(qRevP, multiplyPermutations(q, pRev));
                int[] prefPower = new int[n];
                int[] temp = new int[n];
                int pow = (k - 4) / 6;
                power(pref, pow, prefPower, temp);
                int[] post = ArrayUtils.reversePermutation(prefPower);
                int[] nP = multiplyPermutations(prefPower, multiplyPermutations(multiplyPermutations(qRev,
                        multiplyPermutations(pRev, q)), post));
                int[] nQ = multiplyPermutations(prefPower, multiplyPermutations(multiplyPermutations(qRevP,
                        multiplyPermutations(qRev, multiplyPermutations(pRev, q))), post));
                p = nP;
                q = nQ;
                k -= 6 * pow + 3;
            }
            for (int i = 0; i < k - 1; i++) {
                int[] next = multiplyPermutations(ArrayUtils.reversePermutation(p), q);
                p = q;
                q = next;
            }
            for (int i = 0; i < n; i++) {
                p[i]++;
            }
            out.printLine(p);
        }

        private void power(int[] p, int n, int[] res, int[] temp) {
            if (n == 0) {
                for (int i = 0; i < res.length; i++) {
                    res[i] = i;
                }
                return;
            }
            if ((n & 1) == 1) {
                power(p, n - 1, temp, res);
                inlineMultiplyPermutations(res, temp, p);
            } else {
                power(p, n >> 1, temp, res);
                inlineMultiplyPermutations(res, temp, temp);
            }
        }

        public static void inlineMultiplyPermutations(int[] result, int[] first, int[] second) {
            int count = first.length;
            for (int i = 0; i < count; i++) {
                result[i] = second[first[i]];
            }
        }

        public static int[] multiplyPermutations(int[] first, int[] second) {
            int count = first.length;
            int[] result = new int[count];
            for (int i = 0; i < count; i++) {
                result[i] = second[first[i]];
            }
            return result;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class ArrayUtils {
        public static int[] reversePermutation(int[] permutation) {
            int[] result = new int[permutation.length];
            for (int i = 0; i < permutation.length; i++) {
                result[permutation[i]] = i;
            }
            return result;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }
}