using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
    long mod = 1000000007;
		string s = Console.ReadLine();
    long[][] dp = new long[s.Length+1][];
    for(long i = 0; i < s.Length+1; i++)
    {
      dp[i] = new long[4];
    }
    
    dp[0][0] = 1;
    
    for(int i = 1; i < s.Length+1; i++)
    {
      if(s[i-1] != '?') dp[i][0] = dp[i-1][0];
      else dp[i][0] = dp[i-1][0] * 3;
      dp[i][0] %= mod;
      
      if(s[i-1] == 'A' || s[i-1] == '?') dp[i][1] += dp[i-1][0];
      if(s[i-1] != '?') dp[i][1] += dp[i-1][1];
      else dp[i][1] += dp[i-1][1] * 3;
      dp[i][1] %= mod;

      if(s[i-1] == 'B' || s[i-1] == '?') dp[i][2] += dp[i-1][1];
      if(s[i-1] != '?') dp[i][2] += dp[i-1][2];
      else dp[i][2] += dp[i-1][2] * 3;
      dp[i][2] %= mod;

      if(s[i-1] == 'C' || s[i-1] == '?') dp[i][3] += dp[i-1][2];
      if(s[i-1] != '?') dp[i][3] += dp[i-1][3];
      else dp[i][3] += dp[i-1][3] * 3;
      dp[i][3] %= mod;
    }
		Console.WriteLine(dp[s.Length][3]);//WriteLine?Write?????????????
	}
}