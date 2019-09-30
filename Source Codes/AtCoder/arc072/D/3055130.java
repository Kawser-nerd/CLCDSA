import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;

public class Main {
    static long __startTime = System.currentTimeMillis();

    static class Water {
        double temp;
        long volume;


        public Water(double t, long v) {
            temp = t;
            volume = v;
        }

        public void mergeInto(Water w) {
            double total = w.temp * w.volume + temp * volume;
            w.volume += volume;
            w.temp = total / w.volume;
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long L = in.nextInt();
        Water[] waters = new Water[n];
        for (int i = 0; i < n ; i++) {
            waters[i] = new Water(in.nextInt(), in.nextInt());
        }


        Deque<Water> deq = new ArrayDeque<>();
        deq.push(new Water(0, 0));

        long total = 0;
        double amount = 0;

        for (int i = 0; i < n ; i++) {
            while (total + waters[i].volume > L) {
                long needToTrash = total + waters[i].volume - L;
                Water cold = deq.peekFirst();

                long canTrash = Math.min(needToTrash, cold.volume);
                total -= canTrash;
                amount -= canTrash * cold.temp;
                cold.volume -= canTrash;
                if (cold.volume == 0) {
                    deq.pollFirst();
                }
            }

            total += waters[i].volume;
            amount += waters[i].volume * waters[i].temp;
            out.println(String.format("%.12f", amount / total));

            Water wantToPush = waters[i];
            while (true) {
                Water last = deq.peekLast();
                if (last == null || last.temp <= wantToPush.temp) {
                    deq.addLast(wantToPush);
                    break;
                } else {
                    wantToPush.mergeInto(last);
                    wantToPush = deq.pollLast();
                }
            }
        }
        out.flush();
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}