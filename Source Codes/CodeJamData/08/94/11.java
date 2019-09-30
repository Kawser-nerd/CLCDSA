import com.sun.jmx.remote.internal.ArrayQueue;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class D {
    private int fx, fy, n, m;
    private int[][] di, a;
    private int[][] prev;
    private boolean[][] fd;

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("D-small-attempt0.in"));
        PrintWriter out = new PrintWriter("d.out");

        int T = in.nextInt();
        for (int tt = 1; tt <= T; tt++) {
            D dd = new D();
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[n][m];
            dd.n = n; dd.m = m;
            for (int i = 0; i < n; i++) {
                String s = in.next();
                for (int j = 0; j < m; j++) {
                    char c = s.charAt(j);
                    a[i][j] = c != '.' ? 1 : 0;
                    if (c == 'T' && (i > 0 || j > 0)) {
                      dd.fx = i; dd.fy = j;
                    }
                }
            }
            dd.a = a;
            dd.di = new int[n][m];
            dd.prev = new int[n][m];
            dd.fd = new boolean[n][m];
            for (int[] ints : dd.di) {
                Arrays.fill(ints, 1000000);
            }
            dd.go(0, 0);
            dd.fix();
            dd.go(dd.fx, dd.fy);

            int r = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != 0) {
                        r += dd.di[i][j];
                    }
                }
            }    
            out.println("Case #" + tt + ": " + r);
        }

        in.close();
        out.close();
    }

    private void go(int x0, int y0) {
        Set<Integer> vis = new HashSet<Integer>();
        Queue<Integer> q = new ArrayDeque<Integer>(3*n*m+1);
        q.add(x0*m + y0);
        q.add(0);
        int[][] dirs = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};
        while (!q.isEmpty()) {
            Integer xy = q.poll();
            Integer k = q.poll();
            vis.add(xy);
            int x = xy / m, y = xy % m;
            if (k < di[x][y]) {
                if (!fd[x][y]) {
                    di[x][y] = k;
                }
                for (int[] dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != 0) {
                        Integer nxy = m*nx + ny;
                        if (vis.add(nxy)) {
                            prev[nx][ny] = xy;
                            q.add(nxy);
                            q.add(k + 1);
                        }
                    }
                }
            }
        }
    }

    private void fix() {
        int cx = fx, cy = fy;
        fd[0][0] = true;
        while (cx != 0 || cy != 0) {
            fd[cx][cy] = true;
            int xy = prev[cx][cy];
            cx = xy / m;
            cy = xy % m;
        }
    }
}