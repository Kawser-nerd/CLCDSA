import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }

        int sum = 0;
        for (int i = 0; i < n ; i++) {
            sum += a[i];
        }
        int half = (sum + 1) / 2;

        BitVector bit = BitVector.canMake(a);
        for (int i = half ; i <= sum ; i++) {
            if (bit.get(i)) {
                out.println(i);
                break;
            }
        }
        out.flush();
    }

    public static class BitVector {
        public int n;
        public int m;
        public long[] bits;

        public BitVector(int length) {
            n = length;
            bits = new long[(n+63)>>>6];
            m = bits.length;
        }

        public void set(int at) {
            bits[at>>>6] |= 1L<<(at&63);
        }

        public void set(int at, boolean s) {
            if (s) {
                bits[at>>>6] |= 1L<<(at&63);
            } else {
                bits[at>>>6] &= ~(1L<<(at&63));
            }
        }

        public boolean get(int at) {
            int big = at >>> 6 ;
            if (big >= bits.length) {
                return false;
            }
            return ((bits[big] >>> (at&63)) & 1) == 1;
        }

        public BitVector shiftLeft(int l) {
            BitVector ret = new BitVector(n+l);
            int big = l >>> 6;
            int small = l & 63;
            for (int i = 0; i < m ; i++) {
                ret.bits[i+big] |= bits[i] << small;
            }
            if (small >= 1) {
                for (int i = 0; i+big+1 < ret.m; i++) {
                    ret.bits[i+big+1] |= (bits[i] >>> (64-small));
                }
            }
            return ret;
        }

        public BitVector or(BitVector o) {
            BitVector ans = new BitVector(Math.max(n, o.n));
            for (int i = 0; i < ans.m ; i++) {
                if (i < m) {
                    ans.bits[i] = bits[i];
                }
                if (i < o.m) {
                    ans.bits[i] |= o.bits[i];
                }
            }
            return ans;
        }

        public static BitVector canMake(int[] x) {
            Map<Integer,Integer> cnt = new HashMap<>();
            for (int i = 0; i < x.length ; i++) {
                cnt.put(x[i], cnt.getOrDefault(x[i],0)+1);
            }
            List<Integer> t = new ArrayList<>();
            for (int k : cnt.keySet()) {
                int v = cnt.get(k);
                int l = 1;
                while (l <= v) {
                    v -= l;
                    t.add(k * l);
                    l *= 2;
                }
                if (v >= 1) {
                    t.add(k * v);
                }
            }
            Collections.sort(t);

            BitVector v = new BitVector(1);
            v.set(0);
            for (int ti : t) {
                v = v.or(v.shiftLeft(ti));
            }
            return v;
        }

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