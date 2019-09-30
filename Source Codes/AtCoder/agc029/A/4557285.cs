using System;
public class c
{
  public static void Main()
  {
    string S= Console.ReadLine();
    
            int sum = S.Length;
 
            long wSum = 0;
            long ans = 0;
 
            for(int i = 0; i < sum; i++)
            {
                if (S[sum - i - 1] == 'W')
                {
                    wSum++;
                }
                else
                {
                    ans += wSum;
                }
            }
    Console.WriteLine(ans);
  }
}