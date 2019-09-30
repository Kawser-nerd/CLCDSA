using System;

class Program
{
    //Level k ???p?????
    static readonly long[] dp = new long[51];
    static readonly long[] lengthDp = new long[51];

    static void SetDP(int n, int i)
    {
        dp[i] = dp[i - 1] * 2 + 1;
        lengthDp[i] = lengthDp[i - 1] * 2 + 3;
        i++;
        if (i <= n) SetDP(n, i);
    }
    
    //B/set[n-1]/P/set[n-1]/???B
    static long GetRightPCount(int n, long x, int originalN)
    {
        long count = 0;
        
        //B
        if (x <= 1) return count;
        x--;

        if (n == 0) return count;
        n--;//????index = i - 1

        //set[i-1]
        if (x < lengthDp[n])
            return count + GetRightPCount(n, x, originalN);
        count += dp[n];
        x -= lengthDp[n];
        if (x == 0) return count;

        //P
        count++;
        x--;

        //set[i-1]
        if (x < lengthDp[n])
            return count + GetRightPCount(n, x, originalN);
        count += dp[n];
        x -= lengthDp[n];
        return count;
    }

    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        long x = long.Parse(input[1]);

        dp[0] = 1;
        lengthDp[0] = 1;
        SetDP(n, 1);
        
        Console.WriteLine(GetRightPCount(n, x, n));
    }
}