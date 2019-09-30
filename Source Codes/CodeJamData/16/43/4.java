
import java.io.*;
import java.util.StringTokenizer;

public class C {

    int r, c, n;
    char[][] a;


    private String solveTest() throws IOException {
        r = nextInt();
        c = nextInt();
        a = new char[r][c];
        n = (r + c) * 2;
        int[] q = new int[n];
        for (int i = 0; i < n; i++) q[i] = nextInt() - 1;
        int[] op = new int[n];
        for (int i = 0; i < n; i++) {
            op[q[i ^ 1]] = q[i];
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) p[i] = i;
        while (p.length > 0) {
            boolean ok = false;
            for (int i = 0; i < p.length; i++) {
                int x = p[i];
                int y = p[(i + 1) % p.length];
                if (y == op[x]) {

                    if (!connect(x, y)) {
                        return "\nIMPOSSIBLE";
                    }

                    ok = true;
                    int[] pp = new int[p.length - 2];
                    int m = 0;
                    for (int e : p) {
                        if (e != x && e != y) {
                            pp[m++] = e;
                        }
                    }
                    p = pp;
                    break;
                }
            }
            if (!ok) {
                return "\nIMPOSSIBLE";
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == 0) a[i][j] = '/';
            }
        }
        String res = "";
        for (int i = 0; i < r; i++) {
            res += '\n';
            for (int j = 0; j < c; j++) {
                res += a[i][j];
            }
        }
        return res;
    }

    private boolean connect(int A, int B) {
        int x = getX(A);
        int y = getY(A);
        int tx = getX((B + 1) % n);
        int ty = getY((B + 1) % n);
        int dx = A < c ? 1 : A < (r + c) ? -1 : A < r + c + c ? -1 : 1;
        int dy = A < c ? 1 : A < (r + c) ? 1 : A < r + c + c ? -1 : -1;
        int cc = 0;
        while (x != tx || y != ty) {
            cc++;
            if (cc > n * 100) return false;
            if (canMove(x, y, dx, dy)) {

                x += dx;
                y += dy;

                int t = dy;
                dy = -dx;
                dx = t;
            } else {
                int t = dy;
                dy = dx;
                dx = -t;
            }
        }
        return true;
    }

    private boolean canMove(int x, int y, int dx, int dy) {
        int x2 = x + dx;
        int y2 = y + dy;
        if (x2 < 0 || x2 > c || y2 < 0 || y2 > r) return false;
        int rr = Math.min(y, y2);
        int cc = Math.min(x, x2);
        char c = a[rr][cc];
        char tc = (dx == dy) ? '\\' : '/';
        if (c == 0 || c == tc) {
            a[rr][cc] = tc;
            return true;
        } else {
            return false;
        }
    }

    private int getY(int A) {
        return A < c ? 0 : A < (r + c) ? A - c : A < (r + c + c) ? r: r - (A - r - c - c);
    }

    private int getX(int A) {
        return A < c ? A : A < (r + c) ? c : A < (r + c + c) ? c - (A - r - c) : 0;
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}