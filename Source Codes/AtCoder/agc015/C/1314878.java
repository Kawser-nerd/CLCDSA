import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt(), M = in.nextInt(), Q = in.nextInt();
            String[] S = new String[N + 1];
            char[] s0 = new char[M + 1];
            Arrays.fill(s0, '_');
            S[0] = new String(s0);
            for (int i = 1; i < N + 1; i++) {
                S[i] = "_" + in.next();
            }
//            System.out.println("S " + Arrays.toString(S));

            int[][] kuro = new int[N + 1][M + 1];
            int[][] tate = new int[N + 1][M + 1];
            int[][] yoko = new int[N + 1][M + 1];
            for (int i = 1; i < N + 1; i++) {
                int ki = 0, ti = 0, yi = 0;
                for (int j = 1; j < M + 1; j++) {
                    kuro[i][j] = kuro[i - 1][j];
                    tate[i][j] = tate[i - 1][j];
                    yoko[i][j] = yoko[i - 1][j];
                    if (S[i].charAt(j) == '1') {
                        ki += 1;
                        if (S[i - 1].charAt(j) == '1') {
                            ti += 1;
                        }
                        if (S[i].charAt(j - 1) == '1') {
                            yi += 1;
                        }
                    }
                    kuro[i][j] += ki;
                    tate[i][j] += ti;
                    yoko[i][j] += yi;
                }
            }
//            System.out.println("kuro " + Arrays.deepToString(kuro));
//            System.out.println("tate " + Arrays.deepToString(tate));
//            System.out.println("yoko " + Arrays.deepToString(yoko));

            StringBuilder ans = new StringBuilder();
            for (int q = 0; q < Q; q++) {
                int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
                int cum_kuro = cum(kuro, x1, y1, x2, y2);
                int cum_tate = cum(tate, x1 + 1, y1, x2, y2);
                int cum_yoko = cum(yoko, x1, y1 + 1, x2, y2);
//                System.out.println("cums " + cum_kuro + " " + cum_tate + " " + cum_yoko);

                ans.append(cum_kuro - cum_tate - cum_yoko).append('\n');
            }
            System.out.println(ans);
        }
    }

    private static int cum(int[][] mat, int x1, int y1, int x2, int y2) {
        x1 -= 1;
        y1 -= 1;
//        System.out.println(mat[x1][y1]);
//        System.out.println(mat[x2][y2]);
//        System.out.println(mat[x1][y2]);
//        System.out.println(mat[x2][y1]);
        return mat[x1][y1] + mat[x2][y2] - mat[x1][y2] - mat[x2][y1];
    }
}