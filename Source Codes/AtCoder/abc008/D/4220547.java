import java.util.*;

public class Main {
    static HashMap<Integer, Integer> x = new HashMap<>(); // id -> X
    static HashMap<Integer, Integer> y = new HashMap<>(); // id -> Y
    static HashMap<Integer, Integer> xr = new HashMap<>(); // X -> id
    static HashMap<Integer, Integer> yr = new HashMap<>(); // Y -> id

    static int[][][][] memo = new int[35][35][35][35];

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        int[] X = new int[n];
        int[] Y = new int[n];

        x.put(n, -1);
        xr.put(-1, n);
        y.put(n, -1);
        yr.put(-1, n);
        x.put(n + 1, w);
        xr.put(w, n + 1);
        y.put(n + 1, h);
        yr.put(h, n + 1);

        for (int i = 0; i < n; i++) {
            X[i] = sc.nextInt() - 1;
            Y[i] = sc.nextInt() - 1;

            x.put(i, X[i]);
            y.put(i, Y[i]);
            xr.put(X[i], i);
            yr.put(Y[i], i);

        }

        x.put(-1, 0);
        x.put(-2, w);
        y.put(-1, 0);
        y.put(-2, h);

        for (int i = 0; i < memo.length; i++) {
            for (int j = 0; j < memo.length; j++) {
                for (int k = 0; k < memo.length; k++) {
                    Arrays.fill(memo[i][j][k], -1);
                }
            }
        }

        int ans = s(-1, -1, w, h, new boolean[n], X, Y);

        System.out.println(ans);
    }

    static int s(int xs, int ys, int xe, int ye, boolean[] use, int[] xl, int[] yl) {
        int xsp = xr.get(xs);
        int ysp = yr.get(ys);
        int xep = xr.get(xe);
        int yep = yr.get(ye);
        if (memo[xsp][ysp][xep][yep] != -1)
            return memo[xsp][ysp][xep][yep];

        int max = 0;
        for (int i = 0; i < use.length; i++) {
            if (use[i])
                continue;
            use[i] = true;
            int xp = xl[i];
            int yp = yl[i];

            if (xs < xp && xp < xe && ys < yp && yp < ye) {
                int sum = 1 + xe - xs - 2 + ye - ys - 2;
                int as = sum + s(xp, yp, xe, ye, use, xl, yl) + s(xs, ys, xp, yp, use, xl, yl)
                        + s(xs, yp, xp, ye, use, xl, yl) + s(xp, ys, xe, yp, use, xl, yl);
                max = Math.max(max, as);
            }
            use[i] = false;
        }

        memo[xsp][ysp][xep][yep] = max;
        return max;
    }

}