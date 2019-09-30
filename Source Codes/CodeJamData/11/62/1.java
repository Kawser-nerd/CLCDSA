import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    private int h, w;

    private String solve(Scanner in) {
        h = in.nextInt() + 2;
        w = in.nextInt() + 2;
        long m = in.nextLong();
        long[][] a = new long[h][w];
        for (int i = 0; i < h - 2; i++) {
            for (int j = 0; j < w - 2; j++) {
                a[i + 1][j + 1] = in.nextLong();
            }
        }
        long res = 0;
        outer: while (true) {
            long[][] aa = new long[h][w];
            boolean finish = true;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    aa[i][j] = a[i][j];
                    if (aa[i][j] > 0) finish = false;
                }
            }
            if (finish) break;
            while (true) {
                boolean[][] z = new boolean[h][w];
                boolean[][] zz = new boolean[h][w];
                boolean[][] zzz = new boolean[h][w];
                dfs1(0, 0, z, aa);
                boolean ok = true;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (!z[i][j]) {
                            ok = false;
                            long r = dfs2(i, j, z, zz, aa);
                            dfs3(i, j, zz, zzz, aa, r);
                        }
                    }
                }
                if (ok) {
                    long[][] mm = new long[h][w];
                    long time = Long.MAX_VALUE;
                    for (int i = 1; i < h - 1; i++) {
                        for (int j = 1; j < w - 1; j++) {
                            long e = Long.MAX_VALUE;
                            for (int d = 0; d < 4; d++) {
                                int ii = i + di[d];
                                int jj = j + dj[d];
                                e = Math.min(e, aa[ii][jj]);
                            }
                            mm[i][j] = Math.min(aa[i][j] - e, m);
                            if (mm[i][j] > 0) {
                                long t = (aa[i][j] + mm[i][j] - 1) / mm[i][j];
                                time = Math.min(time, t);
                            }
                        }
                    }
                    time = 1;
                    for (int i = 1; i < h - 1; i++) {
                        for (int j = 1; j < w - 1; j++) {
                            a[i][j] = Math.max(a[i][j] - time * mm[i][j], 0);
                        }
                    }
//                    System.out.println(time);
//                    for (int i = 0; i < h; i++) {
//                        for (int j = 0; j < w; j++) {
//                            System.out.print(a[i][j] + " ");
//                        }
//                        System.out.println();
//                    }
                    res += time;
                    continue outer;
                }
            }
        }
        return "" + res;
    }

    private void dfs3(int i, int j, boolean[][] zz, boolean[][] zzz, long[][] aa, long r) {
        if (zzz[i][j]) return;
        zzz[i][j] = true;
        aa[i][j] = Math.max(aa[i][j], r);
//        aa[i][j] = r;//Math.max(aa[i][j], r);
        for (int d = 0; d < 4; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if (ii >= 0 && ii < h && jj >= 0 && jj < w && zz[ii][jj]) {
                dfs3(ii, jj, zz, zzz, aa, r);
            }
        }
    }

    private long dfs2(int i, int j, boolean[][] z, boolean[][] zz, long[][] a) {
        if (zz[i][j]) return Long.MAX_VALUE;
        zz[i][j] = true;
        long res = Long.MAX_VALUE;
        for (int d = 0; d < 4; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if (ii >= 0 && ii < h && jj >= 0 && jj < w) {
                if (z[ii][jj]) {
                    res = Math.min(res, a[ii][jj]);
                } else {
                    res = Math.min(res, dfs2(ii, jj, z, zz, a));
                }
            }
        }
        return res;
    }

    int[] di = {-1, 1, 0, 0};
    int[] dj = {0, 0, -1, 1};

    private void dfs1(int i, int j, boolean[][] z, long[][] a) {
        if (z[i][j]) return;
        z[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if (ii >= 0 && ii < h && jj >= 0 && jj < w && a[ii][jj] >= a[i][j]) {
                dfs1(ii, jj, z, a);
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}