using System;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        var s2 = "";
        for (int i=0; i<s.Length; i+=2)
        {
            s2 += s[i];
        }
        Console.WriteLine(s2);
    }
}