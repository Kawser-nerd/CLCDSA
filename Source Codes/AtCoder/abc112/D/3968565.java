import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            List<Integer> pn = Numbers.generatePrimeNumbers((int) Math.sqrt(m));
            Set<Integer> div = new TreeSet<>();

            div.add(1);
            int cm = m;
            for (int cpn : pn) {
                while (cm % cpn == 0) {
                    Set<Integer> nd = new TreeSet<>();
                    for (int cd : div)
                        nd.add(cpn * cd);
                    div.addAll(nd);
                    cm /= cpn;
                }
            }
            Set<Integer> nd = new TreeSet<>();
            for (int cd : div)
                nd.add(cm * cd);
            div.addAll(nd);

            int ans = 1;
            for (int cn : div) {
                if (cn >= n) {
                    out.println(m / cn);
                    return;
                }
                ans = cn;
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

    static class Numbers {
        public static List<Integer> generatePrimeNumbers(int max) {
            List<Integer> primeNumbers = new ArrayList<>();

            boolean[] isPrime = new boolean[max + 1];
            Arrays.fill(isPrime, true);

            for (int i = 2; i <= max; i++) {
                if (isPrime[i]) {
                    primeNumbers.add(i);
                    for (long j = (long) i * (long) i; j <= max; j += i)
                        isPrime[(int) j] = false;
                }
            }

            return primeNumbers;
        }

    }
}