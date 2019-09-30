import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int C = sc.nextInt();

        int TIME = 100001;
        int[][] acc = new int[TIME][C + 1];
        for (int i = 0; i < N; i++) {
            int s = sc.nextInt();
            int t = sc.nextInt();
            int c = sc.nextInt();

            acc[s][c] += 1;
            acc[t][c] -= 1;
        }

        for (int t = 1; t < TIME; t++) {
            for (int c = 1; c <= C; c++) {
                acc[t][c] = acc[t][c] + acc[t - 1][c];
            }
        }

        // 0.5????
        for (int t = 1; t < TIME; t++) {
            for (int c = 1; c <= C; c++) {
                if (acc[t][c] > 0 && acc[t - 1][c] != acc[t][c]) {
                    acc[t - 1][c] += acc[t][c];
                }
            }
        }

        int needMaxCnt = 0;
        for (int t = 1; t < TIME; t++) {
            int tmpMaxCnt = 0;
            for (int c = 1; c <= C; c++) {
                tmpMaxCnt += acc[t][c];
            }
            needMaxCnt = Math.max(needMaxCnt, tmpMaxCnt);
        }

        out.println(needMaxCnt);
    }
}