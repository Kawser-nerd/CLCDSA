import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class E {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("e.in"));
        out = new PrintWriter("e.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new E().solve());
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] q = new int[n];
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            q[i] = 0;
            w[i] = 0;
            for (int j = 0; j < m; j++) {
                char c = s.charAt(j);
                q[i] *= 2;
                w[i] *= 2;
                if (c != '#') q[i] += 1;
                if (c != '.') w[i] += 1;
            }
        }
        int[][][] d = new int[n + 1][m + 1][1 << m];
        for (int[][] ints : d) {
            for (int[] anInt : ints) {
                Arrays.fill(anInt, -100000000);
            }
        }
        d[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int qq = 0; qq < (1 << m); qq++) {
                    if (d[i][j][qq] >= 0) {
                        if (((q[i] >> j) & 1) != 0) {
                            int dd = d[i][j][qq];
                            int qqq = qq;
                            if (j > 0 && (((qq >> (j - 1)) & 1) > 0)) dd++;
                            if (((qq >> j) & 1) > 0) {
                                qqq ^= (1 << j);
                                dd++;
                            }
                            d[i][j + 1][qqq] = Math.max(d[i][j +1][qqq], dd);
                        }
                        if (((w[i] >> j) & 1) != 0) {
                            int dd = d[i][j][qq];
                            int qqq = qq;
                            if (j > 0 && (((qq >> (j - 1)) & 1) == 0)) dd++;
                            if (j == 0) dd++;
                            if (j == (m - 1)) dd++;
                            if (i == (n - 1)) dd++;
                            if (((qq >> j) & 1) == 0) {
                                qqq ^= (1 << j);
                                dd++;
                            }
                            d[i][j + 1][qqq] = Math.max(d[i][j +1][qqq], dd);
                        }
                    }
                }
            }
            for (int qq = 0; qq < (1 << m); qq++) {
                d[i + 1][0][qq] = d[i][m][qq];
            }
        }
        int res = 0;
        for (int qq = 0; qq < (1 << m); qq++) {
            res = Math.max(res, d[n][0][qq]);
        }
        return res;
    }
}