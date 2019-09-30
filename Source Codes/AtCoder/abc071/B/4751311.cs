using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().ToCharArray();
        Array.Sort(s);

        var ans = 'a';
        for (int i = 0; i < s.Length; i++)
        {
            if (ans == s[i])
            {
                ans++;
            }
        }

        if ('z' < ans)
        {
            Console.WriteLine("None");
        }
        else
        {
            Console.WriteLine(ans);
        }
    }
}