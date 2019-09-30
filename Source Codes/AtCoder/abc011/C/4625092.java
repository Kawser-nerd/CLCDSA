import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] NG = new int[3];
        for (int i = 0; i < 3; i++) {
            NG[i] = sc.nextInt();
            if(NG[i] == N){
                out.println("NO");
                return;
            }
        }

        int[] dp = new int[303];  //??N??????????
        Arrays.fill(dp, -1);
        dp[N] = 100;

        for(int i = N - 1; i >= 0; i--){
            if(i == NG[0] || i == NG[1] || i == NG[2]){
                continue;
            }

            for(int j: new int[]{1,2,3}){
                dp[i] = Math.max(dp[i + j] - 1, dp[i]);
            }
        }

        if(dp[0] >= 0){
            out.println("YES");
        } else {
            out.println("NO");
        }
    }
}