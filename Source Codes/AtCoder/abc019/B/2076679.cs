using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int[] num = new int[s.Length];
        int c = 0;
        if (s.Length > 1)
        {
            for (int i = 0; i < s.Length - 1; i++)
            {
                if (s[i] != s[i + 1])
                {
                    num[c] = i;
                    c++;
                }
            }
        }
        num[c] = s.Length - 1;
        Console.Write(s[0] + (num[0] + 1).ToString());
        if (c >= 1)
        {
            for (int i = 1; i <= c; i++)
            {
                Console.Write(s[num[i]] + (num[i] - num[i - 1]).ToString());
            }
        }
        Console.WriteLine();
    }
}