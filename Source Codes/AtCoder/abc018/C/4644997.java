import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        // o: 0, x:1
        int[][] cum = new int[R + 1][C + 1];
        for (int i = 0; i < R; i++) {
            String s = sc.next();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == 'x') {
                    cum[i + 1][j + 1] = 1;
                }
            }
        }

        // ????????
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                cum[r][c] += cum[r - 1][c];
            }
        }

        // (x,y)??????
        int ans = 0;
        for (int x = K; x <= R - K + 1; x++) {
            for (int y = K; y <= C - K + 1; y++) {
                boolean ok = true;

                // (x,y)?????K-1??
                int jLeft = y - (K - 1);
                int jRight = y + (K - 1);

                if (jLeft < 1 || jRight > C) {
                    continue;
                }

                for (int j = jLeft; j <= jRight; j++) {
                    int iUp = x + Math.abs(j - y) - (K - 1);
                    int iDown = x - Math.abs(j - y) + (K - 1);

                    if (iUp < 1 || iDown > R || cum[iDown][j] - cum[iUp - 1][j] != 0) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans++;
                }
            }
        }

        out.println(ans);
    }
}