import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int h = in.nextInt();
        int w = in.nextInt();
        boolean[][] a = new boolean[h][w];
        int[] x = new int[10];
        int[] y = new int[10];
        int m = 0;
        for (int i = 0; i < h; i++) {
            String s = in.next();
            for (int j = 0; j < w; j++) {
                char c = s.charAt(j);
                a[i][j] = c != '#';
                if (c >= '0' && c <= '9') {
                    int k = c - '0';
                    y[k] = i;
                    x[k] = j;
                    m = Math.max(m, k + 1);
                }
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < m; i++) {
            res.append("\n").append(i).append(": ").append(calc(a, x[i], y[i]));
        }
        return res.toString();
    }

    private String calc(boolean[][] a, int x, int y) {
        int h = a.length;
        int w = a[0].length;
        boolean[][] z = new boolean[h][w];
        dfs(a, z, x, y);
        int num = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (z[i][j]) num++;
            }
        }
        int[] dx = {-1, 1, 0};
        int[] dy = {0, 0, 1};
        boolean[][] zz = z;
        while (true) {
            boolean ok = false;
            for (int d = 0; d < 2; d++) {
                boolean[][] zzz = z;
                while (canMove(z, zz, a, -dx[d], dy[d])) {
                    z = move(z, a, -dx[d], dy[d]);
                }
                for (int i = 0; i < w; i++) {
                    if (canMove(z, zz, a, 0, 1)) {
                        z = move(z, a, 0, 1);
                        ok = true;
                        break;
                    }
                    if (canMove(z, zz, a, dx[d], dy[d])) {
                        z = move(z, a, dx[d], dy[d]);
                    } else {
                        break;
                    }
                }
                if (ok) break;
                z = zzz;
            }
            if (!ok) {
                break;
            } else {
            }
        }
        boolean lucky = true;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (z[i][j] && (i != y)) lucky = false;
            }
        }
        return num + " " + (lucky ? "Lucky" : "Unlucky");

    }

    private boolean[][] move(boolean[][] z, boolean[][] a, int dx, int dy) {
        int h = z.length;
        int w = z[0].length;
        boolean[][] zz = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                if (z[i][j]) {
                    int ii = i + dy;
                    int jj = j + dx;
                    if (a[ii][jj]) {
                        zz[ii][jj] = true;
                    } else {
                        zz[i][j] = true;
                    }
                }
        }
        return zz;
    }

    private boolean canMove(boolean[][] z, boolean[][] zz, boolean[][] a, int dx, int dy) {
        boolean ok = true;
        boolean ok2 = false;
        for (int i = 0; i < z.length; i++) {
            for (int j = 0; j < z[0].length; j++)
                if (z[i][j]) {
                    int ii = i + dy;
                    int jj = j + dx;
                    if (zz[ii][jj]) {
                        ok2 = true;
                    } else if (a[ii][jj]) {
                        ok = false;
                        break;
                    }
                }
            if (!ok) break;
        }
        return ok && ok2;
    }

    private void dfs(boolean[][] a, boolean[][] z, int x, int y) {
        if (!a[y][x]) return;
        if (z[y][x]) return;
        z[y][x] = true;
        dfs(a, z, x - 1, y);
        dfs(a, z, x + 1, y);
        dfs(a, z, x, y - 1);
    }
}