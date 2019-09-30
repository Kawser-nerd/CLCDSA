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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();
            String[] ymd = s.split("/");
            int y = Integer.parseInt(ymd[0]);
            int m = Integer.parseInt(ymd[1]);
            int d = Integer.parseInt(ymd[2]);

            TaskB.Date date = new TaskB.Date(y, m, d);
            while ((double) date.getY() / (double) date.getM() / (double) date.getD() % 1.0 != 0) {
                date.nextDay();
            }

            out.println(date);
        }

        static class Date {
            private int y;
            private int m;
            private int d;
            private static int[] md = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            Date(int y, int m, int d) {
                this.y = y;
                this.m = m;
                this.d = d;
            }

            void nextDay() {
                d++;
                if (isNextMonth()) {
                    d = 1;
                    if (m < 12)
                        m++;
                    else {
                        y++;
                        m = 1;
                    }
                }
            }

            private boolean isNextMonth() {
                if (m == 2)
                    return isLeapYear() ? d > 29 : d > 28;
                else
                    return d > md[m];
            }

            private boolean isLeapYear() {
                return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
            }

            int getY() {
                return y;
            }

            int getM() {
                return m;
            }

            int getD() {
                return d;
            }

            public String toString() {
                String ms = Integer.toString(m);
                if (ms.length() == 1)
                    ms = "0" + ms;
                String ds = Integer.toString(d);
                if (ds.length() == 1)
                    ds = "0" + ds;
                return String.format("%d/%s/%s", y, ms, ds);
            }

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