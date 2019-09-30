import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int[] par;
        public int[] size;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = new int[n + 1];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
                arr[n] ^= arr[i];
            }
            int[] brr = new int[n + 1];
            for (int j = 0; j < n; j++) {
                brr[j] = in.nextInt();
                brr[n] ^= brr[j];
            }
            int[] crr = Arrays.copyOf(arr, n + 1), drr = Arrays.copyOf(brr, n + 1);
            AUtils.sort(crr);
            AUtils.sort(drr);
            for (int i = 0; i <= n; i++) {
                if (crr[i] != drr[i]) {
                    out.println(-1);
                    return;
                }
            }

            for (int i = 0; i <= n; i++) {
                arr[i] = Arrays.binarySearch(crr, arr[i]);
                brr[i] = Arrays.binarySearch(crr, brr[i]);
            }

            int ans = 0;
            createSets(n + 1);
            for (int i = 0; i < n; i++) {
                if (arr[i] != brr[i]) {
                    ans++;
                }
                unite(arr[i], brr[i]);
            }
            HashSet<Integer> comps = new HashSet<>();
            int single = 0;
            for (int i = 0; i <= n; i++) {
                int x = root(i);
                comps.add(x);
                if (size[x] == 1) single++;
            }
            int need = comps.size() - single;
            if (need > 0 && size[root(arr[n])] == 1) need++;
            ans += Math.max(need - 1, 0);
            out.println(ans);
        }

        public void createSets(int n) {
            par = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                par[i] = i;
                size[i] = 1;
            }
        }

        public int root(int x) {
            return x == par[x] ? x : (par[x] = root(par[x]));
        }

        public boolean unite(int a, int b) {
            a = root(a);
            b = root(b);
            if (a != b) {
                if (Math.random() < 0.5) {
                    par[a] = b;
                    size[b] += size[a];
                } else {
                    par[b] = a;
                    size[a] += size[b];
                }
                return true;
            }
            return false;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static void sort(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

    }
}