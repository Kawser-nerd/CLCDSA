using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        if (s[0] == s[1] && s[1] == s[2] ||
            s[1] == s[2] && s[1] == s[3])
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}