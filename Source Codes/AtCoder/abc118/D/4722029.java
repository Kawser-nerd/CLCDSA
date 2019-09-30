import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] cost = new int[] {0, 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
        int[] nums = new int[M];
        for (int i = 0; i < M; i++) {
            nums[i] = sc.nextInt();
        }

        String[] dp = new String[N+100];
        dp[0] = "";
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (dp[i] == null) continue;
                dp[i + cost[nums[j]]] = max(dp[i + cost[nums[j]]], dp[i] + nums[j]);
            }
        }

        System.out.println(dp[N]);
    }

    private static String max(String a, String b) {
        if (a == null) {
            return b;
        } else if (a.length() < b.length()) {
            return b;
        } else if (a.length() == b.length()) {
            if (a.compareTo(b) < 0) {
                return b;
            }
        }
        return a;
    }
}