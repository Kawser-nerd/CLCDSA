import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt(), P = sc.nextInt(), Q = sc.nextInt(), R = sc.nextInt();
        int choco[][] = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                choco[i][j] = 0;
            }
        }
        for (int i = 0; i < R; i++) {
            int x = sc.nextInt() - 1, y = sc.nextInt() - 1, z = sc.nextInt();
            choco[x][y] = z;
        }

        int ans = 0;
        int comb = (1 << P) - 1;
        while (comb < (1 << N)) {
            int men[] = new int[M];
            for (int i = 0; i < M; i++) {
                men[i] = 0;
            }
            for (int i = 0; i < N; i++) {
                if ((comb >> i & 1) == 1) {
                    for (int j = 0; j < M; j++) {
                        men[j] += choco[i][j];
                    }
                }
            }
            Arrays.sort(men);
            int cand = 0;
            for (int i = 0; i < Q; i++) {
                cand += men[M - i - 1];
            }
            ans = Math.max(ans, cand);

            int x = comb & -comb, y = comb + x;
            comb = ((comb & ~y) / x >> 1) | y;
        }
        System.out.println(ans);
    }
}