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
            int sx = in.nextInt();
            int sy = in.nextInt();
            int tx = in.nextInt();
            int ty = in.nextInt();
            int dx = tx - sx;
            int dy = ty - sy;

            StringBuilder sb = new StringBuilder();

            // first attempt
            for (int i = 0; i < dx; i++)
                sb.append('R');
            for (int i = 0; i < dy; i++)
                sb.append('U');
            for (int i = 0; i < dx; i++)
                sb.append('L');
            for (int i = 0; i < dy; i++)
                sb.append('D');

            // second attempt
            sb.append('D');
            for (int i = 0; i < dx + 1; i++)
                sb.append('R');
            for (int i = 0; i < dy + 1; i++)
                sb.append('U');
            sb.append('L');
            sb.append('U');
            for (int i = 0; i < dx + 1; i++)
                sb.append('L');
            for (int i = 0; i < dy + 1; i++)
                sb.append('D');
            sb.append('R');

            out.println(sb);
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public long nextLong() {
            long n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

        public int nextInt() {
            long n = nextLong();

            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
                throw new NumberFormatException();

            return (int) n;
        }

    }
}