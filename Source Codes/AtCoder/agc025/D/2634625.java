import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[][] svd1;
        int[][] svd2;
        int[][] data;

        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();
            int d1 = in.nextInt();
            int d2 = in.nextInt();
            svd1 = fillSq(d1);
            svd2 = fillSq(d2);

            data = new int[n * 2][n * 2];
            boolean[][] vis = new boolean[n * 2][n * 2];
            for (int s = 0; s < n * 2; s++) {
                for (int x = 0; x < n * 2; x++) {
                    if (vis[s][x]) continue;
                    vis[s][x] = true;
                    fillf(vis, s, x, svd1, 1, 1);
                }
            }


            vis = new boolean[n * 2][n * 2];
            for (int s = 0; s < n * 2; s++) {
                for (int x = 0; x < n * 2; x++) {
                    if (vis[s][x]) continue;
                    vis[s][x] = true;
                    fillf(vis, s, x, svd2, 2, 2);
                }
            }
//        for(int [] r : data) {
//            System.out.println(Arrays.toString(r));
//        }
            for (int s = 0; s < 4; s++) {
                int sum = 0;
                for (int l = 0; l < n * 2; l++) {
                    for (int l1 = 0; l1 < n * 2; l1++) {
                        if (data[l][l1] == s) {
                            sum++;
                        }
                    }
                }

                if (sum >= n * n) {
                    sum = 0;
                    for (int l = 0; l < n * 2; l++) {
                        for (int l1 = 0; l1 < n * 2; l1++) {
                            if (data[l][l1] == s) {
                                out.println(l + " " + l1);
                                sum++;
                            }
                            if (sum == n * n) return;
                        }
                    }
                }
            }

        }

        private int[][] fillSq(int d) {
            ArrayList<int[]> ans = new ArrayList<>();
            int mm = (int) Math.sqrt(d);
            for (int r = -mm; r <= mm; r++) {
                int off = d - r * r;
                int l = (int) Math.sqrt(off);
                if (l * l == off) {
                    if (l == 0) {
                        ans.add(new int[]{0, r});
                    } else {
                        ans.add(new int[]{-l, r});
                        ans.add(new int[]{l, r});
                    }
                }
            }
            return ans.toArray(new int[ans.size()][]);
        }

        private void fillf(boolean[][] vis, int posx, int posy, int[][] svd, int point, int meta) {
            for (int[] p : svd) {
                int nx = posx + p[0];
                int ny = posy + p[1];
                if (nx >= vis.length || ny >= vis.length || nx < 0 || ny < 0 || vis[nx][ny]) {
                    continue;
                }
                vis[nx][ny] = true;
                data[nx][ny] += point;
                fillf(vis, nx, ny, svd, meta - point, meta);
            }
        }

    }

    static class MyScan {
        private final InputStream in;
        private byte[] inbuf = new byte[1024];
        public int lenbuf = 0;
        public int ptrbuf = 0;

        public MyScan(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}