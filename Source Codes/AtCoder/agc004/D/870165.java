import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            @Override
            public void run() {
                InputStream inputStream = System.in;
                OutputStream outputStream = System.out;
                FastScannerTokenizer in = new FastScannerTokenizer(inputStream);
                FastPrinter out = new FastPrinter(outputStream);
                TaskD solver = new TaskD();
                solver.solve(1, in, out);
                out.close();

            }
        }, "", 1 << 27).start();
    }

    static class TaskD {
        static List<Integer>[] edges;
        static int[] kill;
        static int[] left;
        static int k;

        public void solve(int testNumber, FastScannerTokenizer in, FastPrinter out) {
            int n = in.nextInt();
            k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt() - 1;
            int ans = 0;
            if (a[0] != 0) {
                a[0] = 0;
                ans++;
            }
            edges = new List[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<>();
            }
            for (int i = 1; i < n; i++) {
                edges[a[i]].add(i);
            }
            kill = new int[n];
            left = new int[n];
            dfs(0);
            out.println(kill[0] + ans);
        }

        static void dfs(int v) {
            kill[v] = 0;
            left[v] = 0;
            for (int it = 0; it < edges[v].size(); it++) {
                int to = edges[v].get(it);
                dfs(to);
                kill[v] += kill[to];
                if (left[to] == k - 1 && v != 0) {
                    kill[v]++;
                } else {
                    left[v] = Math.max(left[v], left[to] + 1);
                }
            }
        }

    }

    static class FastScannerTokenizer {
        BufferedReader br;
        StringTokenizer st;
        IOException happened;

        public FastScannerTokenizer(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public boolean hasNext() {
            while (st == null || !st.hasMoreTokens()) {
                String line;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    happened = e;
                    return false;
                }
                if (line == null) {
                    return false;
                }
                st = new StringTokenizer(line);
            }
            return true;
        }

//    public String next() {
//        if (!hasNext()) {
//            return null;
//        }
//        return st.nextToken();
//    }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = br.readLine();
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    happened = e;
                    return null;
                }
            }
            return st.nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = br.readLine();
                    if (line == null) {
                        return null;
                    }
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    happened = e;
                    return null;
                }
            }
            return st.nextToken();
        }

        public int indianNextInt() {
            String e = nextToken();
            if (e == null) {
                return 0;
            }
            return Integer.parseInt(e);

        }

        public int fastNextInt() {
            try {
                int c = br.read();
                while (c <= 32 && c >= 0) {
                    c = br.read();
                }
                if (c == -1) {
                    throw new NoSuchElementException();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = br.read();
                }
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                int ret = 0;
                while (c >= '0' && c <= '9') {
                    ret = ret * 10 + c - '0';
                    c = br.read();
                }
                if (c > 32) {
                    throw new NumberFormatException("space character expected "
                            + (char) c + " found");
                }
                return ret * sgn;
            } catch (IOException e) {
                return Integer.MIN_VALUE;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                if (st != null && st.hasMoreTokens()) {
                    StringBuilder ret = new StringBuilder();
                    while (st.hasMoreElements()) {
                        ret.append(st.nextElement());
                    }
                    return ret.toString();
                } else {
                    String line = br.readLine();
                    return line;
                }
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }

        public void skipLine() {
            if (st == null || !st.hasMoreElements()) {
                try {
                    br.readLine();
                } catch (IOException e) {
                    happened = e;
                    return;
                }
            } else {
                st = null;
            }
        }

        public int readTimeHM(char delim) {
            String s = next();
            int pos = s.indexOf(delim);
            if (pos < 0) {
                throw new NumberFormatException("no delim found");
            }
            return Integer.parseInt(s.substring(0, pos)) * 60 + Integer.parseInt(s.substring(pos + 1));
        }

        public int readTimeHMS(char delim1, char delim2) {
            String s = next();
            int pos = s.indexOf(delim1);
            if (pos < 0) {
                throw new NumberFormatException("no delim found");
            }
            int pos2 = s.indexOf(delim2, pos + 1);
            if (pos2 < 0) {
                throw new NumberFormatException("no second delim found");
            }
            return Integer.parseInt(s.substring(0, pos)) * 3600 + Integer.parseInt(s.substring(pos + 1, pos2)) * 60
                    + Integer.parseInt(s.substring(pos2 + 1));
        }

        public int readTimeHMS(char delim) {
            return readTimeHMS(delim, delim);
        }
    }


    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.