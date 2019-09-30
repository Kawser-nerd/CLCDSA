import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class B {
    private static final int INF = 1000000000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("B.in"));
        PrintWriter out = new PrintWriter("B.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
            System.out.println("" + (tn + 1) + " of " + t);
        }

        out.close();

    }

    static int h, w, f;
    static char[][] a;

    private static String solve(Scanner in) {
        h = in.nextInt();
        w = in.nextInt();
        f = in.nextInt();
        a = new char[h + 1][w + 2];
        for (int i = 0; i < h; i++) {
            a[i][0] = '#';
            a[i][w + 1] = '#';
            String s = in.next();
            for (int j = 0; j < w; j++) {
                a[i][j + 1] = s.charAt(j);
            }
        }
        Arrays.fill(a[h], '#');
        int j = 1;
        while (a[0][j + 1] == '.' && a[1][j + 1] == '#') j++;

        for (int[][] ints : z) {
            for (int[] anInt : ints) {
                Arrays.fill(anInt, -1);
            }
        }

        int res = count(0, 1, j);

        return res == INF ? "No" : "Yes " + res;
    }

    static int[][][] z = new int[52][52][52];

    private static int count(int y, int l1, int r1) {
        if (y == h - 1) return 0;
        if (z[y][l1][r1] == -1) {
            int res = INF;

            boolean bl = false;
            boolean br = false;
            int l = l1;
            int r = r1;

            if (a[y + 1][l] == '.') {
                l = l + 1;
                bl = true;
            }
            if (a[y + 1][r] == '.') {
                r = r - 1;
                br = true;
            }

            //Jump left
            if ((a[y][l - 1] == '.' || bl) && a[y + 1][l - 1] == '.') {
                int yy = y;
                while (a[yy + 1][l - 1] == '.') yy++;
                if (yy - y <= f) {
                    int ll = l - 1;
                    while (a[yy][ll - 1] == '.' && a[yy + 1][ll - 1] == '#') ll--;
                    int rr = l - 1;
                    while (a[yy][rr + 1] == '.' && a[yy + 1][rr + 1] == '#') rr++;
                    res = Math.min(res, count(yy, ll, rr));
                }
            }

            //Jump right
            if ((a[y][r + 1] == '.' || br) && a[y + 1][r + 1] == '.') {
                int yy = y;
                while (a[yy + 1][r + 1] == '.') yy++;
                if (yy - y <= f) {
                    int ll = r + 1;
                    while (a[yy][ll - 1] == '.' && a[yy + 1][ll - 1] == '#') ll--;
                    int rr = r + 1;
                    while (a[yy][rr + 1] == '.' && a[yy + 1][rr + 1] == '#') rr++;
                    res = Math.min(res, count(yy, ll, rr));
                }
            }

            //Digging
            if (r > l) {
                //Jump more than one cell
                for (int x = l; x <= r; x++) {
                    if (a[y + 2][x] == '.') {
                        int yy = y + 2;
                        while (a[yy + 1][x] == '.') yy++;
                        if (yy - y <= f) {
                            int ll = x;
                            while (a[yy][ll - 1] == '.' && a[yy + 1][ll - 1] == '#') ll--;
                            int rr = x;
                            while (a[yy][rr + 1] == '.' && a[yy + 1][rr + 1] == '#') rr++;
                            res = Math.min(res, 1 + count(yy, ll, rr));
                        }
                    }
                }

                // Make hall left to right
                for (int rr = l; rr < r; rr++) if (a[y + 2][rr] == '#') {
                    int j = rr;
                    while (j > l && a[y + 2][j] == '#') j--;
                    for (int ll = j; ll <= rr; ll++) {
                        int lll = ll;
                        if (ll == l && a[y + 2][ll] == '#') {
                            while (a[y + 1][lll - 1] == '.' && a[y + 2][lll - 1] == '#') lll--;
                        }
                        res = Math.min(res, (rr - ll + 1) + count(y + 1, lll, rr));
                    }
                }

                // Make hall right to left
                for (int ll = l + 1; ll <= r; ll++) if (a[y + 2][ll] == '#') {
                    int j = ll;
                    while (j < r && a[y + 2][j] == '#') j++;
                    for (int rr = ll; rr <= j; rr++) {
                        int rrr = rr;
                        if (rr == r && a[y + 2][rr] == '#') {
                            while (a[y + 1][rrr + 1] == '.' && a[y + 2][rrr + 1] == '#') rrr++;
                        }
                        res = Math.min(res, (rr - ll + 1) + count(y + 1, ll, rrr));
                    }
                }
            }
            z[y][l1][r1] = res;
        }
        return z[y][l1][r1];
    }

}