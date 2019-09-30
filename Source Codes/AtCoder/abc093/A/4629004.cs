using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var t = "abc";

        var all = true;
        for (int i = 0; i < 3; i++)
        {
            var any = false;
            for (int j = 0; j < 3; j++)
            {
                if (t[i] == s[j])
                {
                    any |= true;
                }
            }
            all &= any;
        }

        Console.WriteLine(all ? "Yes" : "No");
    }
}