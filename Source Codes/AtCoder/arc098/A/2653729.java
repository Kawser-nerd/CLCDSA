import java.io.*;
import java.util.*;

public class Main {
    private static FastScanner scanner;
    private static Main solver;

    private static int n;
    private static char[] ss;
    private static int[] cost;

    public static void main(String[] args) {
        solver = new Main();
        scanner = solver.new FastScanner();

        n = scanner.nextInt();
        scanner.skipLine();

        ss = new char[n];
        cost = new int[n];
        scanner.nextChars(ss);

        try {
            solver.solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void solve() {
        int ec = ss[0] == 'W' ? 1 : 0;
        int wc = ss[n-1] == 'E' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            cost[i] += ec;
            cost[n-1-i] += wc;
            if (ss[i] == 'W') ec++;
            if (ss[n-1-i] == 'E') wc++;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            min = Math.min(min, cost[i]);
        }
        System.out.println(min);
    }

    private static int getLowerBound(int[] target, int key) {
        int l = 0;
        int r = target.length - 1;
        int m = (l + r) / 2;
        while (true) {
            if (target[m] == key || target[m] > key) {
                r = m - 1;
                if (r < l)
                    return m;
            } else {
                l = m + 1;
                if (r < l)
                    return m < target.length - 1 ? m + 1 : -1;
            }
            m = (l + r) / 2;
        }
    }

    private static int getUpperBound(int[] target, int key) {
        int l = 0;
        int r = target.length - 1;
        int m = (l + r) / 2;
        while (true) {
            if (target[m] == key || target[m] < key) {
                l = m + 1;
                if (r < l)
                    return m < target.length - 1 ? m + 1 : -1;
            } else {
                r = m - 1;
                if (r < l)
                    return m;
            }
            m = (l + r) / 2;
        }
    }

    private class FastScanner implements Closeable {
        private InputStream inputStream = System.in;
        private byte[] buffer = new byte[1024];
        private int pointer = 0;
        private int bufferLength = 0;
        private boolean[] isSpace = new boolean[128];

        public FastScanner() {
            this(System.in);
        }

        public FastScanner(InputStream inputStream, char...spaces) {
            this.setSpace(spaces);
            this.inputStream = inputStream;
        }

        public FastScanner(String string, char...spaces) {
            this.setSpace(spaces);
            this.buffer = string.getBytes();
            this.bufferLength = this.buffer.length;
        }

        public void setSpace(char...spaces) {
            Arrays.fill(isSpace, false);
            isSpace[' '] = isSpace['\n'] = isSpace['\r'] = isSpace['\t'] = true;
            for (char space : spaces) isSpace[space] = true;
        }

        @Override
        public void close() {
            try {
                if (this.inputStream != null) this.inputStream.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        public int read() {
            if (this.bufferLength == -1) return -1;
            if (this.pointer >= this.bufferLength) {
                this.pointer = 0;
                if (this.inputStream == null) return this.bufferLength = -1;
                try {
                    this.bufferLength = this.inputStream.read(this.buffer);
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
                if (this.bufferLength <= 0) return -1;
            }
            return this.buffer[this.pointer++];
        }

        public int peek() {
            int c = this.read();
            if (c >= 0) this.pointer--;
            return c;
        }

        public boolean hasNext() {
            int c = this.read();
            while (c >= 0 && this.isSpace[c]) c = this.read();
            if (c == -1) return false;
            this.pointer--;
            return true;
        }

        public boolean hasNextInLine() {
            if (this.pointer > 0 && this.buffer[this.pointer - 1] == '\n') return false;
            int c = this.read();
            while (c >= 0 && this.isSpace[c] && c != '\n' && c != '\r') c = this.read();
            if (c == -1) return false;
            this.pointer--;
            return c != '\n' && c != '\r';
        }

        public void skipLine() {
            if (this.pointer > 0 && this.buffer[this.pointer - 1] == '\n') {
                this.buffer[this.pointer - 1] = ' ';
                return;
            }
            int c = this.read();
            if (c < 0) return;
            while (c >= 0 && c != '\n' && c != '\r') {
                c = this.read();
            }
            if (c == '\r') this.read();
            if (this.pointer > 0) this.buffer[this.pointer - 1] = ' ';
        }

        public String next() {
            if (!this.hasNext()) throw new InputMismatchException();
            StringBuilder sb = new StringBuilder();
            int c = this.read();
            while (c >= 0 && !this.isSpace[c]) {
                sb.append((char)c);
                c = this.read();
            }
            return sb.toString();
        }

        public String nextLine() {
            StringBuilder sb = new StringBuilder();
            if (this.pointer > 0 && this.buffer[this.pointer - 1] == '\n') {
                this.buffer[this.pointer - 1] = ' ';
                return "";
            }
            int c = this.read();
            if (c < 0) throw new InputMismatchException();
            while (c >= 0 && c != '\n' && c != '\r') {
                sb.append((char)c);
                c = this.read();
            }
            if (c == '\r') this.read();
            if (this.pointer > 0) this.buffer[this.pointer - 1] = ' ';
            return sb.toString();
        }

        public int nextChar(){
            if (!this.hasNext()) throw new InputMismatchException();
            int c = 0;
            do {
                c = this.read();
            } while (this.isSpace[c]);
            return c;
        }

        public int nextChars(char[] chars) {
            int l = 0;
            while (l < chars.length && this.hasNextInLine()) {
                chars[l++] = (char) this.nextChar();
            }
            if (this.hasNextInLine()) return -1;
            return l;
        }

        public int nextInt() {
            if (!this.hasNext()) throw new InputMismatchException();
            int c = this.read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = this.read();
            }
            int acc = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                acc *= 10;
                acc += c - '0';
                c = this.read();
            } while (c >= 0 && !this.isSpace[c]);
            return acc * sgn;
        }

        public int nextInts(int[] ints) {
            int l = 0;
            while (l < ints.length && this.hasNextInLine()) {
                ints[l++] = this.nextInt();
            }
            if (this.hasNextInLine()) return -1;
            return l;
        }

        public long nextLong() {
            if (!this.hasNext()) throw new InputMismatchException();
            int c = this.read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = this.read();
            }
            long acc = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                acc *= 10;
                acc += c - '0';
                c = this.read();
            } while (c >= 0 && !this.isSpace[c]);
            return acc * sgn;
        }

        public int nextLongs(long[] longs) {
            int l = 0;
            while (l < longs.length && this.hasNextInLine()) {
                longs[l++] = this.nextLong();
            }
            if (this.hasNextInLine()) return -1;
            return l;
        }

        public double nextDouble() {
            return Double.parseDouble(this.next());
        }

        public int nextDoubles(double[] doubles) {
            int l = 0;
            while (l < doubles.length && this.hasNextInLine()) {
                doubles[l++] = this.nextDouble();
            }
            if (this.hasNextInLine()) return -1;
            return l;
        }
    }
}