import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();

        long ANum = solver(A - 1);
        long BNum = solver(B);

        out.println(BNum - ANum);
    }

    // [0, N]???4,9?????????
    public static long solver(long N) {
        if(N < 0){ return 0; }
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
            if(k > 0 && (first == 4 || first == 9)){
                ans += N - first * (long) Math.pow(10, k) + 1;
                break;
            } else {
                N %= first * (long)Math.pow(10.0, k);
            }
        }

        return ans;
    }
}