using System;
using System.Text;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        var s2 = new StringBuilder();
        for (int i=0; i<s.Length; i+=2)
        {
            s2.Append(s[i]);
        }
        Console.WriteLine(s2);
    }
}