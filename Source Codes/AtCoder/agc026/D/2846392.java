import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int mul(int x, int y) {
        return (int) ((x * 1L * y) % mod);
    }

    int pow(int x, int y) {
        if (y == 0) {
            return 1;
        }
        int t = pow(x, y / 2);
        t = mul(t, t);
        if (y % 2 == 1) {
            t = mul(t, x);
        }
        return t;
    }

    class Position {
        int left, right, h;
        int lValue, rValue;
        boolean changed;

        public Position(int left, int right, int h, int lValue, int rValue, boolean changed) {
            this.left = left;
            this.right = right;
            this.h = h;
            this.lValue = lValue;
            this.rValue = rValue;
            this.changed = changed;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Position position = (Position) o;
            return left == position.left &&
                    right == position.right &&
                    h == position.h &&
                    lValue == position.lValue &&
                    rValue == position.rValue &&
                    changed == position.changed;
        }

        @Override
        public int hashCode() {
            return Objects.hash(left, right, h, lValue, rValue, changed);
        }

        @Override
        public String toString() {
            return "Position{" +
                    "left=" + left +
                    ", right=" + right +
                    ", h=" + h +
                    ", lValue=" + lValue +
                    ", rValue=" + rValue +
                    ", changed=" + changed +
                    '}';
        }
    }

    HashMap<Position, Integer> ans = new HashMap<>();

    int calcAns(Position p) {
        if (p.left == p.right && p.lValue != p.rValue) {
            return 0;
        }
//        if (p.h == 1 && p.lValue == 0 && p.rValue == 0 && p.changed == false && p.left == 0 && p.right== 1) {
//            System.err.println("!!!");
//        }
        int cnt = p.right - p.left + 1;
        if (cnt == 2 && p.changed == false && p.lValue != p.rValue) {
            return 0;
        }
        if (cnt == 1 && p.changed == false) {
            return 0;
        }
        if (p.changed) {
            if (cnt % 2 == 0) {
                if (p.lValue == p.rValue) {
                    return 0;
                }
            } else {
                if (p.lValue != p.rValue) {
                    return 0;
                }
            }
        }
        int min = minH[p.left][p.right];
        if (min != p.h) {
            if (p.changed) {
                int diff = min - p.h;
                int mul = pow(2, diff - 1);
                int res = 0;
                for (int lVal = 0; lVal < 2; lVal++) {
                    for (int rVal = 0; rVal < 2; rVal++) {
                        res = add(res, getAns(new Position(p.left, p.right, min, lVal, rVal, true)));
                    }
                }
                return mul(mul, res);
            } else {
                int diff = (min - p.h) % 2;
                return getAns(new Position(p.left, p.right, min, p.lValue ^ diff, p.rValue ^ diff, p.changed));
            }
        } else {
            if (maxH[p.left][p.right] == p.h) {
                if (p.changed) {
                    return 1;
                } else {
                    int res =  pow(2, cnt - 2);
                    if (cnt % 2 == 0) {
                        if (p.lValue != p.rValue) {
                            res--;
                        }
                    } else {
                        if (p.lValue == p.rValue) {
                            res--;
                        }
                    }
                    if (res < 0) {
                        res += mod;
                    }
                    return res;
                }
            } else {
                boolean eqH = h[p.left] == p.h;
                for (int pos = p.left + 1; pos <= p.right; pos++) {
                    boolean curEqH = (h[pos] == p.h);
                    if (curEqH != eqH) {
                        int res = 0;
                        for (int x = 0; x < 2; x++) {
                            for (int y = 0; y < 2; y++) {
                                for (int z1 = 0; z1 < 2; z1++) {
                                    for (int z2 = 0; z2 < 2; z2++) {
                                        boolean c1 = z1 == 0, c2 = z2 == 0;
                                        boolean nextChange = c1 && c2 && (x != y);
                                        if (nextChange != p.changed) {
                                            continue;
                                        }
                                        int f = mul(getAns(new Position(p.left, pos - 1, p.h, p.lValue, x, c1)), getAns(new Position(pos, p.right, p.h, y, p.rValue, c2)));
                                        res = add(res, f);
                                    }
                                }
                            }
                        }
                        return res;
                    }
                }
                throw new AssertionError();
            }
        }
    }

    int getAns(Position p) {
        if (ans.containsKey(p)) {
            return ans.get(p);
        }
        int r = calcAns(p);
//        if (r != 0 && p.h == 2 && p.left == 1 && p.right == 1)
//            System.err.println(p + " -> " + r);
        ans.put(p, r);
        return r;
    }

    int n;
    int[] h;
    int[][] minH;
    int[][] maxH;

    void solve() {
        n = in.nextInt();
        h = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt();
        }
        minH = new int[n][n];
        maxH = new int[n][n];
        for (int i = 0; i < n; i++) {
            int f = Integer.MAX_VALUE;
            int g = 0;
            for (int j = i; j < n; j++) {
                f = Math.min(f, h[j]);
                g = Math.max(g, h[j]);
                minH[i][j] = f;
                maxH[i][j] = g;
            }
        }
        int res = 0;
        for (int l = 0; l < 2; l++) {
            for (int r = 0; r < 2; r++) {
                res = add(res, getAns(new Position(0, n - 1, 1, l, r, true)));
                res = add(res, getAns(new Position(0, n - 1, 1, l, r, false)));
            }
        }
        out.println(res);
    }


    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}