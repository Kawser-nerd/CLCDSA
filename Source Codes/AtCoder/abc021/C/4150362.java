import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
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
            int n = in.nextInt();
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int m = in.nextInt();
            int mod = 1000000007;
            int[] count = new int[n];
            int[] x = new int[m];
            int[] y = new int[m];
            for (int i = 0; i < m; i++) {
                x[i] = in.nextInt() - 1;
                y[i] = in.nextInt() - 1;
                count[x[i]]++;
                count[y[i]]++;
            }
            int[][] g = new int[n][];
            for (int i = 0; i < n; i++)
                g[i] = new int[count[i]];
            for (int i = 0; i < m; i++) {
                g[x[i]][--count[x[i]]] = y[i];
                g[y[i]][--count[y[i]]] = x[i];
            }

            Set<Integer> fSet = new HashSet<>();
            fSet.add(a);
            boolean[] visited = new boolean[n];
            int[] path = new int[n];
            visited[a] = true;
            path[a] = 1;
            while (true) {
                Set<Integer> tSet = new HashSet<>();
                for (int f : fSet) {
                    if (f == b) {
                        out.println(path[b]);
                        return;
                    }
                    for (int t : g[f]) {
                        if (visited[t])
                            continue;
                        path[t] = (path[f] + path[t]) % mod;
                        tSet.add(t);
                    }
                }
                for (int t : tSet)
                    visited[t] = true;
                fSet = tSet;
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int nextInt() {
            int n = 0;

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
}