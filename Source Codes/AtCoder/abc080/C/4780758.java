import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int DAYS = 5;
        int TIME = 2;
        int[][][] F = new int[N][DAYS][TIME];
        for (int n = 0; n < N; n++) {
            for (int d = 0; d < DAYS; d++) {
                for (int t = 0; t < TIME; t++) {
                    F[n][d][t] = sc.nextInt();
                }
            }
        }

        int TOGETHER_DAYTIME = 11;
        long[][] P = new long[N][TOGETHER_DAYTIME];
        for (int n = 0; n < N; n++) {
            for (int dt = 0; dt < TOGETHER_DAYTIME; dt++) {
                P[n][dt] = sc.nextLong();
            }
        }

        long max = Long.MIN_VALUE;
        for (int dt = 0; dt < 2 << DAYS * TIME; dt++) {
            long tmpMax = 0;
            boolean haveTogetherShop = false;
            for (int n = 0; n < N; n++) {
                int cnt = 0;
                for (int d1 = 0; d1 < DAYS; d1++) {
                    int timeBit = (dt >> d1 * TIME) & 3;
                    for (int t1 = 0; t1 < TIME; t1++) {
                        if (((timeBit >> t1) & 1) == 1 && F[n][d1][t1] == 1) {
                            cnt++;
                            haveTogetherShop = true;
                        }
                    }
                }
                tmpMax += P[n][cnt];
            }
            if (haveTogetherShop) {
                max = Math.max(max, tmpMax);
            }
        }

        out.println(max);
    }
}