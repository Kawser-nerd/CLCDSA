import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

class C_as {
    Scanner in;
    PrintWriter out;

    int[][] a;
    int[] px;
    int[] py;
    boolean[] u;

    boolean dfs(int x) {
        u[x] = true;
        for (int j = 0; j < 2; j++) {
            if (py[a[x][j]] == -1 || !u[py[a[x][j]]] && dfs(py[a[x][j]])) {
                py[a[x][j]] = x;
                px[x] = a[x][j];
                return true;
            }
        }
        return false;
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.err.println("Test " + test + " of " + testNo);
            int r = in.nextInt();
            int c = in.nextInt();
            a = new int[r * c][2];
            for (int i = 0; i < r; i++) {
                String s = in.next();
                for (int j = 0; j < c; j++) {
                    int ni1 = 0, ni2 = 0;
                    int nj1 = 0, nj2 = 0;
                    switch (s.charAt(j)) {
                        case '|':
                            ni1 = (i - 1 + r) % r;
                            ni2 = (i + 1 + r) % r;
                            nj1 = j;
                            nj2 = j;
                            break;
                        case '-':
                            ni1 = i;
                            ni2 = i;
                            nj1 = (j - 1 + c) % c;
                            nj2 = (j + 1 + c) % c;
                            break;
                        case '/':
                            ni1 = (i + 1 + r) % r;
                            ni2 = (i - 1 + r) % r;
                            nj1 = (j - 1 + c) % c;
                            nj2 = (j + 1 + c) % c;
                            break;
                        case '\\':
                            ni1 = (i - 1 + r) % r;
                            ni2 = (i + 1 + r) % r;
                            nj1 = (j - 1 + c) % c;
                            nj2 = (j + 1 + c) % c;
                            break;
                    }
                    a[i * c + j][0] = ni1 * c + nj1;
                    a[i * c + j][1] = ni2 * c + nj2;
                }
            }

            int n = r * c;
            px = new int[n];
            py = new int[n];
            Arrays.fill(px, -1);
            Arrays.fill(py, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    if (py[a[i][j]] == -1) {
                        py[a[i][j]] = i;
                        px[i] = a[i][j];
                        break;
                    }
                }
            }

            boolean ok = true;
            u = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (px[i] == -1) {
                    Arrays.fill(u, false);
                    if (!dfs(i)) {
                        ok = false;
                        break;
                    }
                }
            }

//            System.out.println(Arrays.toString(px));
//            System.out.println(Arrays.toString(py));

            int ans = 0;
            if (ok) {
                int[] vx = new int[n];
                int[] vy = new int[n];
                Arrays.fill(vx, -1);
                Arrays.fill(vy, -1);

                int cn = 0;
                for (int i = 0; i < n; i++) {
                    if (vx[i] == -1) {
                        int j = i;
                        while (vx[j] == -1) {
                            vx[j] = i;
                            for (int k = 0; k < 2; k++) {
                                if (a[j][k] != px[j]) {
                                    j = py[a[j][k]];
                                    break;
                                }
                            }
                        }
                        if (vx[j] == i) {
                            cn++;
                        }
                    }
                }
                ans = 1;
                for (int i = 0; i < cn; i++) {
                    ans = (ans * 2) % 1000003;
                }
            }
            out.println("Case #" + test + ": " + ans);
        }
    }

    public void run() {
        try {
            in = new Scanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new C_as().run();
    }
}