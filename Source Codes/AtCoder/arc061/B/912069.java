import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;

/**
 * Created by jaga on 9/22/16.
 * ??WA?????
 */
public class Main {
    public static void solve(PrintWriter out, FastScanner in) {
        long H = in.nextInt();
        long W = in.nextInt();
        int N = in.nextInt();

        BigInteger maxEmpty = BigInteger.valueOf(H - 2);
        maxEmpty = maxEmpty.multiply(BigInteger.valueOf(W - 2));

        //
        if (N == 0) {
            out.println(maxEmpty);
            for(int i = 0;i < 9;i++) {
                out.println("0");
            }
            return;
        }

        Pair[] ps = new Pair[9 * N];
        int a, b, idx = 0;

        for (int i = 0; i < N; i++) {
            a = in.nextInt();
            b = in.nextInt();
            for (int dx = 0; dx < 3; dx++) {
                for (int dy = 0; dy < 3; dy++) {
                    int y = a - 1 + dy;
                    int x = b - 1 + dx;
                    if (x >= 2 && x <= W - 1 && y >= 2 && y <= H - 1) {
                        ps[idx++] = new Pair(x, y);
                    }
                }
            }
        }

        //???????
//        Arrays.fill(ps, idx, ps.length, new Pair(-1, -1));
//        Arrays.sort(ps);

        Arrays.sort(ps, 0, idx);
        Pair p;
        int pa = 0;
        int pb = 0;

        if (N != 0) {
            p = ps[0];
            pa = p.first;
            pb = p.second;
        }


        int count = 1; //??????????p?????????????
        BigInteger res[] = new BigInteger[10];
        for (int i = 0; i < 10; i++) {
            res[i] = new BigInteger("0");
        }

        res[0] = new BigInteger(String.valueOf(H - 2));
        res[0] = res[0].multiply(new BigInteger(String.valueOf(W - 2)));

        int sum = 0;
        BigInteger one = new BigInteger("1");

        for (int i = 1; i < idx; i++) {
            p = ps[i];
            if (p.first == pa && p.second == pb) {
                //??????????count?++??
                count++;
            } else {
                //???????
                res[count] = res[count].add(one);
                sum++;
                count = 1;
            }
            pa = p.first;
            pb = p.second;
        }

        res[count] = res[count].add(one);
        sum++;


//        if (N == 1) {
//            res[1] = new BigInteger("1");
//            sum++;
//        }

        out.println(res[0].subtract(new BigInteger(String.valueOf(sum))));

        for (int i = 1; i < res.length; i++) {
            out.println(res[i]);
        }
    }

    static class Pair implements Comparable {
        int first, second;

        Pair(int a, int b) {
            first = a;
            second = b;
        }

        public int compareTo(Object other) {
            Pair p1 = (Pair) other;
            if (this.first == ((Pair) other).first) {
                return this.second - ((Pair) other).second;
            } else {
                return this.first - ((Pair) other).first; // ID????????????????
            }

//            return this.first - ((Pair) other).first; // ID????????????????
//         return -(this.first - ((Pair) other).first); // ID????????????????
        }
    }


    /*???????*/
    public static void main(String args[]) {
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        FastScanner in = new FastScanner();
        solve(out, in);
        out.close();
    }

    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufferLength = 0;

        private boolean hasNextByte() {
            if (ptr < bufferLength) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufferLength = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (bufferLength <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private void skipUnprintable() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        }

        boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextDouble();
            }
            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextDoubleArray(m);
            }
            return map;
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++) array[i] = nextInt();
            return array;
        }

        public long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++) array[i] = nextLong();
            return array;
        }

        public String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++) array[i] = next();
            return array;
        }

        public char[][] nextCharMap(int n) {
            char[][] array = new char[n][];
            for (int i = 0; i < n; i++) array[i] = next().toCharArray();
            return array;
        }

        public int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextIntArray(m);
            }
            return map;
        }
    }
}