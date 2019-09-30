import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();

        long ANum = digitDP(A - 1);
        long BNum = digitDP(B);

        //long ANum = solver(A - 1);
        //long BNum = solver(B);

        out.println(BNum - ANum);
    }

    // ?DP(?dp)
    public static long digitDP(long N) {

        String num = String.valueOf(N);
        int size = num.length();

        // [?][??????N??:1][???????:1] = ??????
        long[][][] dp = new long[size + 1][2][2];


        dp[0][0][0] = 1;  //???????0?????????
        for (int i = 0; i < size; i++) {
            for (int smaller = 0; smaller < 2; smaller++) {
                for (int j = 0; j < 2; j++) {
                    int iNum = Character.getNumericValue(num.charAt(i));
                    for (int x = 0; x <= (smaller == 1 ? 9 : iNum); x++) {
                        dp[i + 1][smaller == 1 || x < iNum ? 1 : 0][j == 1 || cond(x) ? 1 : 0] += dp[i][smaller][j];
                    }
                }
            }
        }

        return dp[size][0][1] + dp[size][1][1];
    }

    public static boolean cond(int n) {
        return n == 4 || n == 9;
    }

    // [0, N]???4,9?????????
    public static long solver(long N) {
        if (N < 0) {
            return 0;
        }
        long ans = 0;

        while (true) {
            // N >= first*10^k??????k????
            int first = Character.getNumericValue(String.valueOf(N).charAt(0));
            int k = String.valueOf(N).length() - 1;

            if (k == 0) {
                for (int i = 0; i <= first; i++) {
                    if (i == 4 || i == 9) {
                        ans++;
                    }
                }
                break;
            } else {
                // [0, first*10^k)?4, 9 ???????
                long ansTmp = first * (long) Math.pow(10.0, k);
                for (int i = 0; i < first; i++) {  //?????
                    if (i == 4 || i == 9) {
                        continue;
                    }
                    ansTmp -= (long) Math.pow(8, k);
                }
                ans += ansTmp;
            }

            // ?????????????
            if (k > 0 && (first == 4 || first == 9)) {
                ans += N - first * (long) Math.pow(10, k) + 1;
                break;
            } else {
                //long?????????????????
                // TODO: ???????
                // ???"0 536262553535523524"???526223286047212465??????526223286047212464???
                // ???mod????1???4?0????????????
                N %= first * (long) Math.pow(10.0, k);
            }
        }

        return ans;
    }
}