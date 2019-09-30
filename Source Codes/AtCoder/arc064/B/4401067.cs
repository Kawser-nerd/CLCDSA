using System;
class P
{
    static void Main()
    {
        string s;
        int l = (s = Console.ReadLine()).Length;
        int j = (l - (s[0] == s[l - 1] ? 1 : 0)) % 2;
        Console.WriteLine(j == 0 ? "Second" : "First");
    }
}