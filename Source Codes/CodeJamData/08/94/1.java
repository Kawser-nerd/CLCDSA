import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.io.File;

public class DHard implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter("D-large.out");

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int H = in.nextInt();
            int W = in.nextInt();
            char[][] f = new char[H][];
            for (int i = 0; i < H; i++) {
                f[i] = in.next().toCharArray();
            }

            int[][] d = new int[H][W];
            for (int i = 0; i < H; i++) {
                Arrays.fill(d[i], Integer.MAX_VALUE);
            }
            boolean[][] cnt = new boolean[H][W];
            cnt[0][0] = true;
            d[0][0] = 0;

            ArrayList<Integer> sx = new ArrayList<Integer>();
            ArrayList<Integer> sy = new ArrayList<Integer>();
            sx.add(0);
            sy.add(0);


            while (true) {
                int[] dx = new int[]{0, -1, 0, 1};
                int[] dy = new int[]{-1, 0, 1, 0};
                int[] qx = new int[H * W];
                int[] qy = new int[H * W];
                int h = 0;
                int t = 0;
                boolean[][] u = new boolean[H][W];
                for (int i = 0; i < sx.size(); i++) {
                    qx[t] = sx.get(i);
                    qy[t] = sy.get(i);
                    u[qx[t]][qy[t]] = true;
                    t++;
                }
                int[][] fx = new int[H][W];
                int[][] fy = new int[H][W];
                int[][] d1 = new int[H][W];
                while (h < t) {
                    for (int i = 0; i < 4; i++) {
                        if (0 <= qx[h] + dx[i] && qx[h] + dx[i] < H && 0 <= qy[h] + dy[i] && qy[h] + dy[i] < W) {
                            if (!u[qx[h] + dx[i]][qy[h] + dy[i]] && f[qx[h] + dx[i]][qy[h] + dy[i]] != '.') {
                                u[qx[h] + dx[i]][qy[h] + dy[i]] = true;
                                qx[t] = qx[h] + dx[i];
                                qy[t] = qy[h] + dy[i];
                                d1[qx[t]][qy[t]] = d1[qx[h]][qy[h]] + 1;
                                fx[qx[t]][qy[t]] = qx[h];
                                fy[qx[t]][qy[t]] = qy[h];
                                t++;
                            }
                        }
                    }
                    h++;
                }

                int best = Integer.MAX_VALUE;
                int tx = 0;
                int ty = 0;
                for (int i = 0; i < H; i++) {
                    for (int j = 0; j < W; j++) {
                        if (!cnt[i][j] && f[i][j] == 'T' && best > d1[i][j]) {
                            tx = i;
                            ty = j;
                            best = d1[i][j];
                        }
                        if (!cnt[i][j] && f[i][j] != '.') {
                            d[i][j] = Math.min(d[i][j], d1[i][j]);
                        }
                    }
                }
                if (tx == 0 && ty == 0) {
                    break;
                }
                sx.add(tx);
                sy.add(ty);
                while (tx != 0 || ty != 0) {
                    cnt[tx][ty] = true;
                    int ntx = fx[tx][ty];
                    int nty = fy[tx][ty];
                    tx = ntx;
                    ty = nty;
                }
            }

            int ans = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (f[i][j] != '.') {
                        ans += d[i][j];
                    }
                }
            }

            System.out.printf("Case #%d: %d\n", test, ans);
            out.printf("Case #%d: %d\n", test, ans);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] s) {
        new Thread(new DHard()).start();
    }
}