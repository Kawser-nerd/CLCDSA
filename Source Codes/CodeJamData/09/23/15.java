import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class C {
    private static final int MAX = 1000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter("C.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        int q = in.nextInt();
        in.nextLine();
        char[][] a = new char[n][];
        for (int y = 0; y < n; y++) {
            String s = in.nextLine();
            a[y] = s.toCharArray();
        }
        int[] qq = new int[q];
        int[] pq = new int[MAX + 1];
        String res[] = new String[q];
        Arrays.fill(pq, -1);
        for (int i = 0; i < q; i++) {
            qq[i] = in.nextInt();
            pq[qq[i]] = i;
        }

        String[][][] d = new String[n][n][2 * MAX + 1];
        String[][][] dd = new String[n][n][2 * MAX + 1];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++)
                if (a[y][x] >= '0' && a[y][x] <= '9') {
                    d[y][x][MAX + (a[y][x] - '0')] = "" + a[y][x];
                }
        }
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        while (true) {
            for (String[][] strings : dd) {
                for (String[] string : strings) {
                    Arrays.fill(string, null);
                }
            }
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    for (int t = -MAX; t <= MAX; t++) {
                        if (d[y][x][t + MAX] != null) {
                            if (t > 0 && pq[t] >= 0) {
                                int i = pq[t];
                                if (res[i] == null ||
                                        res[i].length() == d[y][x][t + MAX].length() &&
                                                res[i].compareTo(d[y][x][t + MAX]) > 0) {
                                    res[i] = d[y][x][t + MAX];
                                }
                            }
                            for (int i = 0; i < 4; i++) {
                                int yy = y + dy[i];
                                int xx = x + dx[i];
                                if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
                                    for (int ii = 0; ii < 4; ii++) {
                                        int yyy = yy + dy[ii];
                                        int xxx = xx + dx[ii];
                                        if (xxx >= 0 && xxx < n && yyy >= 0 && yyy < n) {
                                            int tt = a[yy][xx] == '+' ? t + (a[yyy][xxx] - '0') : t - (a[yyy][xxx] - '0');
                                            if (tt >= -MAX && tt <= MAX) {
                                                String ddd = d[y][x][t + MAX] + a[yy][xx] + a[yyy][xxx];
                                                if (dd[yyy][xxx][tt + MAX] == null ||
                                                        dd[yyy][xxx][tt + MAX].length() > ddd.length() ||
                                                        dd[yyy][xxx][tt + MAX].length() == ddd.length() &&
                                                        dd[yyy][xxx][tt + MAX].compareTo(ddd) > 0) {
                                                    //System.out.println(dd);
                                                    dd[yyy][xxx][tt + MAX] = ddd;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            String[][][] t = d;
            d = dd;
            dd = t;
            boolean ok = true;
            for (String s : res) {
                if (s == null) ok = false;
            }
            if (ok) break;
        }

        String r = "";
        for (String s : res) {
            r += "\n" + s;
        }
        return r;
    }
}
