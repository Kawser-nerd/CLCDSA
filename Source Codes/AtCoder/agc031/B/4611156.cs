using System;
using System.Collections.Generic;

class AGC031 {
    const int MOD = 1000000007;

    static void Main() {
        int N;
        long res = 1;
        int[] tmp = new int[200010]; // ???????DP??????
        N = int.Parse(Console.ReadLine());
        int[] array = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            array[i] = int.Parse(Console.ReadLine());
        }
        int[] dp = new int[N + 1];
        dp[0] = dp[1] = 1; // ???????DP??1
        tmp[array[1]] = 1;

        for(int i = 2; i <= N; i++) {
            if(i == 0 || array[i] == array[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                tmp[array[i]] += dp[i - 1];
                tmp[array[i]] %= MOD;
                dp[i] = tmp[array[i]];
            }
        }
        res = dp[N];

        Console.WriteLine(res);
    }
}