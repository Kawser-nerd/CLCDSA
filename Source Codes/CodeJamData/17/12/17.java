import java.util.*;
import java.io.*;

public class PB implements Runnable {
    static class Data {
        private StringTokenizer tok;
        private final BufferedReader rd;
        private final PrintWriter wr;

        Data() {
            tok = null;
            rd = new BufferedReader(new InputStreamReader(System.in));
            wr = new PrintWriter(System.out);
        }

        Data(String name) throws IOException {
            tok = null;
            rd = new BufferedReader(new FileReader(new File(name + ".in")));
            wr = new PrintWriter(new File(name + ".out"));
        }

        void println(String line) {
            wr.println(line);
        }

        void close() throws IOException {
            rd.close();
            wr.close();
        }

        String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        static Data console() {
            return new Data();
        }

        static Data files(String name) throws IOException {
            return new Data(name);
        }
    }

    public static void main(String[] args) {
        new Thread(new PB()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Throwable t) {
            throw new RuntimeException(t);
        }
    }

    private void solve() throws IOException {
        Data data = Data.files("b");

        int t = data.nextInt();
        for (int i = 0; i < t; ++i) {
            int res = subsolve(data);
            data.println(String.format("Case #%d: %d", i + 1, res));
        }

        data.close();
    }

    static class MinMax {
        final int min;
        final int max;

        MinMax(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }

    private int subsolve(Data data) throws IOException {
        int n = data.nextInt();
        int p = data.nextInt();
        int[] r = new int[n];
        int[][] mat = new int[n][p];
        for (int j = 0; j < n; ++j) {
            r[j] = data.nextInt();
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                mat[j][k] = data.nextInt();
            }
            Arrays.sort(mat[j]);
        }
        int[] cur = new int[n];
        MinMax[] mm = new MinMax[n];
        int res = 0;
        while (true) {
            boolean stop = false;
            for (int i = 0; i < n; ++i) {
                if (cur[i] >= p) {
                    stop = true;
                    break;
                }
            }
            if (stop) {
                break;
            }
            int tmin = Integer.MIN_VALUE;
            int tmax = Integer.MAX_VALUE;
            for (int i = 0; i < n; ++i) {
                mm[i] = findminmax(r[i], mat[i][cur[i]]);
                tmax = Math.min(tmax, mm[i].max);
                tmin = Math.max(tmin, mm[i].min);
            }
            if (tmin > tmax || tmin <= 0 || tmax <= 0) {
                for (int i = 0; i < n; ++i) {
                    if (mm[i].max == tmax) {
                        cur[i] += 1;
                    }
                }
            } else {
                res += 1;
                for (int i = 0; i < n; ++i) {
                    cur[i] += 1;
                }
            }
        }
        return res;
    }

    private MinMax findminmax(int r, int v) {
        int maxx = 10 * v / (9 * r);
        int minx = (10 * v + 11 * r - 1) / (11 * r);
        if (minx > maxx || minx <= 0 || maxx <= 0) {
            return new MinMax(-1, -1);
        }
        return new MinMax(minx, maxx);
    }
}
