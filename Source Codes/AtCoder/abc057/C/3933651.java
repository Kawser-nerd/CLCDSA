import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            long n = in.nextLong();

            List<Integer> pn = Numbers.generatePrimeNumbers((int) Math.sqrt(n));
            List<Long> divisors = new ArrayList<>();
            for (long cpn : pn) {
                while (n % cpn == 0) {
                    n /= cpn;
                    divisors.add(cpn);
                }
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < (1 << divisors.size()); i++) {
                long a = n;
                long b = 1;
                for (int j = 0; j < divisors.size(); j++) {
                    if (((i >> j) & 1) == 1)
                        a *= divisors.get(j);
                    else
                        b *= divisors.get(j);
                }
                ans = Math.min(Math.max(Long.toString(a).length(), Long.toString(b).length()), ans);
            }

            out.println(ans);
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

    }

    static class Numbers {
        public static List<Integer> generatePrimeNumbers(int max) {
            boolean[] isPrime = new boolean[max + 1];
            for (int i = 2; i <= max; i++) isPrime[i] = true;

            int sqrtMax = (int) Math.sqrt(max);
            for (int i = 2; i <= sqrtMax; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= max; j += i) {
                        isPrime[j] = false;
                    }
                }
            }

            ArrayList<Integer> primeNumbers = new ArrayList<>();
            for (int i = 2; i <= max; i++) if (isPrime[i]) primeNumbers.add(i);

            return primeNumbers;
        }

    }
}