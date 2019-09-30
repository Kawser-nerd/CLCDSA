using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var n = long.Parse(Console.ReadLine());

        var i = 0;
        for (i = 0; i < s.Length; i++)
        {
            if (s[i] != '1')
            {
                break;
            }
        }

        if (i < n) Console.WriteLine(s[i]);
        else Console.WriteLine('1');
    }
}