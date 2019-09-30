import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int R = in.nextInt();
        int C = in.nextInt();
        int D = in.nextInt();
        int[][] w = new int[R][C];
        for (int i = 0; i < R; i++) {
            String s = in.next();
            for (int j = 0; j < C; j++) {
                w[i][j] = s.charAt(j) - '0';
            }
        }
        int[][] wi = new int[R][C];
        int[][] wj = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                wi[i][j] = w[i][j] * i;
                wj[i][j] = w[i][j] * j;
            }
        }
        int[][] sw = prepare(w);
        int[][] swi = prepare(wi);
        int[][] swj = prepare(wj);
        int max = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int maxSize = Math.min(R - i, C - j);
                for (int k = 2; k < maxSize; k++) {
                    int si = calc(swi, wi, i, j, k);
                    int sj = calc(swj, wj, i, j, k);
                    int s = calc(sw, w, i, j, k);
                    if (2 * si == (2 * i + k) * s &&
                        2 * sj == (2 * j + k) * s) {
                        max = Math.max(max, k + 1);
                    }
                }
            }
        }

        return max == 0 ? "IMPOSSIBLE" : ("" + max);
    }

    private int calc(int[][] sw, int[][] w, int i, int j, int k) {
        return
                sw[i + k + 1][j + k + 1] - sw[i + k + 1][j] - sw[i][j + k + 1] + sw[i][j] -
                        (w[i][j] + w[i + k][j] + w[i][j + k] + w[i + k][j + k]);
    }

    private int[][] prepare(int[][] w) {
        int R = w.length;
        int C = w[0].length;
        int[][] res = new int[R + 1][C + 1];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res[i + 1][j + 1] =
                        res[i][j + 1] +
                                res[i + 1][j] -
                                res[i][j] +
                                w[i][j];
                if (res[i + 1][j + 1] < 0) {
                    throw new RuntimeException("BOTVA!!");
                }
            }
        }
        return res;
    }
}