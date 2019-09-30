using System;

class Program
{
    static void Main(string[] args)
    {
        string s1 = Console.ReadLine();
        string s2 = Console.ReadLine();
        if (s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0])
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}