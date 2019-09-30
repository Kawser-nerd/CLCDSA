import java.util.Scanner;

/**
 * Created by ishikawanaoki on 2016/08/03.
 */
public class Main {

    final static long MAX = 2000 * 500000 + 1;

    public static void main(String[] args) {

        // Input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        long[] accDays = new long[N+1];
        accDays[0] = 1;
        accDays[1] = sc.nextLong();
        for(int i=2; i<=N; i++){
            accDays[i] = accDays[i-1] + sc.nextLong();
        }

        if(accDays[N] == K){
            System.out.println(1);
            return;
        }

        // Preparation
        long[][] dp = new long[N+1][N+1];
        for(int day=0; day<=N; day++){
            for(int win=0; win<=N; win++){
                dp[day][win] = MAX;
            }
        }
        dp[0][0] = 0;

        // do dp[day][win]
        for(int day=0; day<N; day++){
            for(int win=0; win<day+1; win++){
                // current -> next
                if(dp[day][win] == MAX){
                    continue;
                }

                // calc
                int neededWin = getNeededWin(day, win, accDays, dp);
                if(neededWin+win > K){
                    // ?????
                     break;
                }else{
                    // ??????????????
                    // ??????
                    dp[day+1][win] = Math.min(dp[day+1][win], dp[day][win]);
                    // ????
                    dp[day+1][win+1] = Math.min(dp[day+1][win+1], dp[day][win] + neededWin);
                }
            }
        }


        // find answer from dp table
        int ans = 0;
        for(int win=0; win <=N; win++){
            if(dp[N][win] != MAX && dp[N][win] <= K){
                ans = win;
            }
        }

        // print
        System.out.println(ans);

//        // TODO ????
//        for(int day=0; day<=N; day++){
//            for(int win=0; win<=N; win++){
//                System.out.print(dp[day][win] + "\t");
//            }
//            System.out.println("");
//        }

    }

    private static int getNeededWin(int day, int win, long[] accDays, long[][] dp) {
        // current -> next

        // ????
        double currentRate = ((double)dp[day][win]) / ((double)accDays[day]);

        // ???????????????
        int ret = (int)(currentRate * (accDays[day+1] - accDays[day])) + 1;

        return ret;
    }
}