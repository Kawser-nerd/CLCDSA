import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.io.InputStreamReader;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int h = in.nextInt();
            int w = in.nextInt();
            int k = in.nextInt();

            String[] a = in.nextStringArray(h);

            int y = 0;
            int x = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (a[i].charAt(j) == 'S') {
                        y = i;
                        x = j;
                    }
                }
            }

            int[] dx = {1, 0, -1, 0};
            int[] dy = {0, 1, 0, -1};

            int[][] cnt = new int[h][w];
            ArrayUtils.fill(cnt, Integer.MAX_VALUE);
            ArrayDeque<Pair> queue = new ArrayDeque<>();
            cnt[y][x] = 0;
            queue.add(new Pair(y, x));
            while (!queue.isEmpty()) {
                Pair p = queue.poll();
                if (cnt[p.x][p.y] >= k) continue;

                for (int i = 0; i < 4; i++) {
                    int ty = p.x + dy[i];
                    int tx = p.y + dx[i];

                    if (RangeUtils.isInside(ty, tx, h, w)) {
                        if (a[ty].charAt(tx) != '#') {
                            if (cnt[ty][tx] == Integer.MAX_VALUE) {
                                cnt[ty][tx] = cnt[p.x][p.y] + 1;
                                queue.add(new Pair(ty, tx));
                            }
                        }
                    }
                }
            }

            long ans = Integer.MAX_VALUE;

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (cnt[i][j] != Integer.MAX_VALUE) {
                        int min = Integer.MAX_VALUE;
                        min = Math.min(min, i);
                        min = Math.min(min, j);
                        min = Math.min(min, h - 1 - i);
                        min = Math.min(min, w - 1 - j);

                        ans = Math.min(ans, (min + k - 1) / k + 1);
                    }
                }
            }

            out.println(ans);
        }

        public class Pair {
            int x;
            int y;

            Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

        }

    }

    static class ArrayUtils {
        public static void fill(int[][] array, int x) {
            for (int[] a : array) {
                Arrays.fill(a, x);
            }
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public String[] nextStringArray(int n) {
            String[] res = new String[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextString();
            }
            return res;
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }

    static class RangeUtils {
        public static boolean isInside(int y, int x, int h, int w) {
            return y >= 0 && x >= 0 && y < h && x < w;
        }

    }
}