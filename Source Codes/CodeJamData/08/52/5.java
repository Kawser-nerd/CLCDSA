import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class B {

    static Scanner in;
    static PrintWriter out;
    private static final int INF = 1000000000;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new B().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[][] a = new boolean[n + 2][m + 2];
        int si = 0;
        int sj = 0;
        int ti = 0;
        int tj = 0;
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < m; j++) {
                char c = s.charAt(j);
                a[i + 1][j + 1] = (c != '#');
                if (c == 'O') {
                    si = i + 1;
                    sj = j + 1;
                }
                if (c == 'X') {
                    ti = i + 1;
                    tj = j + 1;
                }
            }
        }

        n += 2;
        m += 2;

        int d[][][][] = new int[n][m][n][m];
        for (int[][][] ints : d) {
            for (int[][] anInt : ints) {
                for (int[] ints1 : anInt) {
                    Arrays.fill(ints1, INF);
                }
            }
        }

        d[si][sj][0][0] = 0;
        int size = n * m * n * m * 2;
        int[] qi = new int[size];
        int[] qj = new int[size];
        int[] qii = new int[size];
        int[] qjj = new int[size];

        int h = -1;
        int t = 0;

        qi[0] = si;
        qj[0] = sj;
        qii[0] = 0;
        qjj[0] = 0;

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        int res = INF;

        while (h != t) {
            h++;
            if (h == size) h = 0;
            int i = qi[h];
            int j = qj[h];
            int ii = qii[h];
            int jj = qjj[h];

            //System.out.println("" + i + " " + j + " " + ii + " " + jj + " " + d[i][j][ii][jj]);

            if (i == ti && j == tj) res = Math.min(res, d[i][j][ii][jj]);

            if (ii == 0 && jj == 0) {
                for (int dd = 0; dd < 4; dd++) {
                    int ni = i;
                    int nj = j;
                    while (a[ni + dx[dd]][nj + dy[dd]]) {
                        ni += dx[dd];
                        nj += dy[dd];
                    }
                    if (d[i][j][ni][nj] > d[i][j][ii][jj]) {
                        d[i][j][ni][nj] = d[i][j][ii][jj];
                        qi[h] = i;
                        qj[h] = j;
                        qii[h] = ni;
                        qjj[h] = nj;
                        if (h == 0) h = size;
                        h--;
                    }
                }
            } else {
                boolean e = false;
                for (int dd = 0; dd < 4; dd++) {
                    int ni = i + dx[dd];
                    int nj = j + dy[dd];
                    if (!a[ni][nj]) e = true;
                }
                if (e) {
                    if (a[ii][jj] && d[ii][jj][0][0] == INF) {
                        d[ii][jj][0][0] = d[i][j][ii][jj] + 1;
                        t++;
                        qi[t] = ii;
                        qj[t] = jj;
                        qii[t] = 0;
                        qjj[t] = 0;
                    }
                }
            }

            for (int dd = 0; dd < 4; dd++) {
                int ni = i + dx[dd];
                int nj = j + dy[dd];
                if (a[ni][nj] && d[ni][nj][ii][jj] == INF) {
                    d[ni][nj][ii][jj] = d[i][j][ii][jj] + 1;
                    t++;
                    qi[t] = ni;
                    qj[t] = nj;
                    qii[t] = ii;
                    qjj[t] = jj;
                }
            }

        }

        return res == INF ? "THE CAKE IS A LIE" : res;
    }
}
