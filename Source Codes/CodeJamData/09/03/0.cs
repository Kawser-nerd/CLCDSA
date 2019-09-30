using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            int tst = int.Parse(Console.ReadLine());
            for (int cas = 0; cas < tst; cas++)
            {
                string s = Console.ReadLine();
                string s1 = "welcome to code jam";
                int len = s.Length;
                int[] dp = new int[len];
                for (int i = 0; i < len; i++)
                {
                    if (s[i]=='w')
                    {
                        dp[i] = 1;
                    }
                }
                for (int i = 1; i < s1.Length; i++)
                {
                    int[] dp1 = new int[len];
                    int sum = 0;
                    for (int j = 0; j < len; j++)
                    {
                        if (s[j]==s1[i])
                        {
                            dp1[j] = sum;
                            

                        }
                        sum = (sum + dp[j])%10000;

                    }
                    dp = dp1;
                }
                int res = 0;
                foreach (var i in dp)
                {
                    res = (res + i)%10000;
                }
                Console.Write("Case #"+(cas+1)+": ");
                List<int> l = new List<int>();
                for (int i = 0; i < 4; i++)
                {
                    
                    l.Add(res%10);
                    res /= 10;
                }
                l.Reverse();
                foreach (var i in l)
                {
                    Console.Write(i);
                }
                Console.WriteLine();

            }
        }
    }
}
