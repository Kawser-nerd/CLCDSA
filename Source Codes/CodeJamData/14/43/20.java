
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {

    private final static int[] dx = {-1, 1, 0, 0};
    private final static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter(new File("C.out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
//            if (i + 1 == 10) {
//                int w = in.nextInt();
//                int h = in.nextInt();
//                int b = in.nextInt();
//                System.out.println(w + " " + h + " " + b);
//                for (int j = 0; j < b; j++) {
//                    System.out.println(in.nextInt() + " " + in.nextInt() + " " + in.nextInt() + " " + in.nextInt());
//                }
//                return;
//            }
            String s = "Case #" + (i + 1) + ": " + new C2().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int w = in.nextInt();
        int h = in.nextInt();
        int b = in.nextInt();
        int[] x0 = new int[b];
        int[] y0 = new int[b];
        int[] x1 = new int[b];
        int[] y1 = new int[b];
        for (int i = 0; i < b; i++) {
            x0[i] = in.nextInt();
            y0[i] = in.nextInt();
            x1[i] = in.nextInt() + 1;
            y1[i] = in.nextInt() + 1;
        }
        int[] d = new int[b];
        for (int i = 0; i < b; i++) {
            d[i] = x0[i];
        }
        boolean[] z = new boolean[b];
        int res = w;
        for (int i = 0; i < b; i++) {
            int x = -1;
            for (int j = 0; j < b; j++) if (!z[j]) {
                if (x == -1 || d[j] < d[x]) x = j;
            }
            z[x] = true;
            res = Math.min(res, d[x] + (w - x1[x]));
//            System.out.println(x + " " + d[x] + " " + (d[x] + (w - x1[x])));
            for (int k = 0; k < b; k++) {
                int dd;
                if (intersect(x0[x], x1[x], x0[k], x1[k]) && intersect(y0[x], y1[x], y0[k], y1[k])) {
                    dd = 0;
                } else if (intersect(x0[x], x1[x], x0[k], x1[k])) {
                    dd = Math.min(Math.abs(y1[x] - y0[k]), Math.abs(y1[k] - y0[x]));
                } else if (intersect(y0[x], y1[x], y0[k], y1[k])) {
                    dd = Math.min(Math.abs(x1[x] - x0[k]), Math.abs(x1[k] - x0[x]));
                } else {
                    dd = Math.max(Math.min(Math.abs(y1[x] - y0[k]), Math.abs(y1[k] - y0[x])),
                            Math.min(Math.abs(x1[x] - x0[k]), Math.abs(x1[k] - x0[x])));
                }
                if (d[x] + dd < d[k]) {
                    d[k] = d[x] + dd;
                }
            }
        }
        return "" + res;
    }

    private boolean intersect(int x1, int x2, int y1, int y2) {
        return Math.max(x1, y1) <= Math.min(x2, y2);
    }

    private int normalize(int[] xx) {
        Arrays.sort(xx);
        int n = 1;
        for (int i = 1; i < xx.length; i++) {
            if (xx[i] != xx[i - 1]) {
                xx[n++] = xx[i];
            }
        }
        return n;
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        cp = new int[m];
        fl = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
    }

    void addEdge(int x, int y, int capacity) {
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        cp[last] = capacity;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        cp[last] = 0;
        head[y] = last;
        last++;
    }

    long maxFlow(int s, int t) {
        long res = 0;
        while (true) {
            Arrays.fill(z, false);
            int f = dfs(s, t, Integer.MAX_VALUE);
            if (f > 0) {
                res += f;
            } else {
                break;
            }
        }
        return res;
    }

    private int dfs(int x, int t, int f) {
        if (f == 0) return 0;
        if (x == t) return f;
        if (z[x]) return 0;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (!z[y] && fl[j] < cp[j]) {
                int res = dfs(y, t, Math.min(f, cp[j] - fl[j]));
                if (res > 0) {
                    fl[j] += res;
                    fl[j ^ 1] -= res;
                    return res;
                }
            }
            j = nx[j];
        }
        return 0;
    }

    private static final long INF = Long.MAX_VALUE;

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] cp;
    int[] fl;
    boolean[] z;
    int last;
}