import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();
            int len = s.length();

            boolean[][] patterns = new boolean[len][len];
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    patterns[i][(i + j) % len] = s.charAt(j) == 'o';
                }
            }

            int p = (int) Math.pow(2, len);
            int min = len;
            for (int i = 1; i < p; i++) {
                int count = 0;
                int[] index = new int[len];
                for (int j = 0; j < len; j++) {
                    if (((i >> j) & 1) == 1) {
                        index[count++] = j;
                    }
                }
                if (count >= min)
                    continue;
                boolean filled = true;
                for (int k = 0; k < len; k++) {
                    boolean hasO = false;
                    for (int j = 0; j < count; j++) {
                        if (patterns[index[j]][k]) {
                            hasO = true;
                            break;
                        }
                    }
                    if (!hasO) {
                        filled = false;
                        break;
                    }
                }
                if (filled)
                    min = count;
            }

            out.println(min);
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

    }
}