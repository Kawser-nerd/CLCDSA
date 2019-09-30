using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var ans = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == '1')
            {
                ans++;
            }
        }
        Console.WriteLine(ans);
    }
}