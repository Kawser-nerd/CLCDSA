import sun.nio.cs.ext.MacArabic;

import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

    private void solve(FastScanner sc) {
        int n = sc.nextInt();
        int[] hist = new int[n + 1];
        int dia = 0;
        for (int i = 0; i < n; i++) {
            int ni = sc.nextInt();
            hist[ni]++;
            dia = Math.max(dia, ni);
        }
        // create diameter path
        for (int i = 0; i <= dia; i++) {
            hist[Math.max(i, dia - i)]--;
        }
        // add node
        boolean possible = true;
        int min = (dia + 1) / 2;
        for (int i = 0; i <= dia; i++) {
            if (i <= min && hist[i] > 0 || i > min && hist[i] < 0) possible = false;
        }
        System.out.println(possible ? "Possible" : "Impossible");
    }

    /*
     * template
     */

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        new Main().solve(sc);
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufLen = 0;

        private boolean hasNextByte() {
            if (ptr < bufLen) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufLen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (bufLen <= 0) {
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

        boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        String next() {
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

        int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static class Pair {

        public int fst;
        public int snd;

        public Pair(int fst, int snd) {
            this.fst = fst;
            this.snd = snd;
        }

        public Pair(List<Integer> list) {
            this.fst = list.get(0);
            this.snd = list.get(1);
        }

        public Pair(int[] array) {
            this.fst = array[0];
            this.snd = array[1];
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;

            Pair pair = (Pair) o;

            return fst == pair.fst && snd == pair.snd;

        }

        @Override
        public int hashCode() {
            int result = fst;
            result = 31 * result + snd;
            return result;
        }

        @Override
        public String toString() {
            return "(" + fst + ", " + snd + ")";
        }

        public void swap() {
            int swap = fst;
            fst = snd;
            snd = swap;
        }
    }
}