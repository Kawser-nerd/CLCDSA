import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int C = sc.nextInt();

        int[][] D = new int[C + 1][C + 1];
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                D[i][j] = sc.nextInt();
            }
        }

        int[][] c = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        // ???c?(i+j)%3???????????????
        int[][] colorNums = new int[C + 1][3];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                colorNums[c[i][j]][(i + j) % 3]++;
            }
        }

        // (i+j)%3??????????????????
        int minDSum = Integer.MAX_VALUE;
        for (int c1 = 1; c1 <= C; c1++) {
            for (int c2 = 1; c2 <= C; c2++) {
                if (c1 == c2) {
                    continue;
                }
                for (int c3 = 1; c3 <= C; c3++) {
                    if (c1 == c3 || c2 == c3) {
                        continue;
                    }

                    int tmp = 0;
                    for (int cOrg = 1; cOrg <= C; cOrg++) {
                        tmp += colorNums[cOrg][0] * D[cOrg][c1];
                        tmp += colorNums[cOrg][1] * D[cOrg][c2];
                        tmp += colorNums[cOrg][2] * D[cOrg][c3];
                    }
                    minDSum = Math.min(minDSum, tmp);
                }
            }
        }

        out.println(minDSum);
    }
}