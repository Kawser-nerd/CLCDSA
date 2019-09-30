using System;

class Problem
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int ans=0, num=0, count =0;
        char[] c = { 'A', 'T', 'C', 'G' };
        
        for(int i=0; i<s.Length; i++)
        {
            for(int j=0; j<4; j++)
            {
                if (c[j] == s[i])
                {
                    num= 1;
                }
            }
            if (num == 1)
            {
                count += 1;
            }
            else
            {
                count = 0;
            }
            ans = Math.Max(count, ans);
            num = 0;
        }
        Console.WriteLine(ans);
    }
    
}