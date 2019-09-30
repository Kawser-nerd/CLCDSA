import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class C {

    static Scanner in;
    static PrintWriter out;
    private int[][] a;
    private int[][] mx;
    private int[][] mn;

    int[] dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int[] dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    private int n;
    private int m;
    private int res;
    private boolean [][] g;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("c.in"));
        out = new PrintWriter("c.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new C().solve());
        }
        out.close();
    }

    private Object solve() {
        n = in.nextInt();
        m = in.nextInt();
        a = new int[n + 2][m + 2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i + 1][j + 1] = in.nextInt();
            }
        }

        mx = new int[n + 2][m + 2];
        mn = new int[n + 2][m + 2];
        g = new boolean[n + 2][m + 2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i + 1][j + 1] = true;
                for (int d = 0; d < 9; d++) {
                    mx[i + 1 + dx[d]][j + 1 + dy[d]]++;
                }
            }
        }

        res = 0;
        bt(1, 1, 0);

        return res;
    }

    private void bt(int x, int y, int s) {
        if (y > m) {
            //System.out.println(s);
            if (s > res) res = s;
        } else if (x > n) {
            bt(1, y + 1, s);
        } else {
            {
            //+
            boolean ok = true;
            for (int i = 0; i < 9; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                mn[xx][yy]++;
                if ((mn[xx][yy] > a[xx][yy]) && (g[xx][yy])) ok = false;
            }
            if (ok) {
                bt(x + 1, y, s + (x == (n / 2 + 1) ? 1 : 0));
            }
            for (int i = 0; i < 9; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                mn[xx][yy]--;
            }
            }
            {
            //-
            boolean ok = true;
            for (int i = 0; i < 9; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                mx[xx][yy]--;
                if (mx[xx][yy] < a[xx][yy] && g[xx][yy]) ok = false;
            }
            if (ok) {
                bt(x + 1, y, s);
            }
            for (int i = 0; i < 9; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                mx[xx][yy]++;
            }
            }
        }
        //To change body of created methods use File | Settings | File Templates.
    }
}
