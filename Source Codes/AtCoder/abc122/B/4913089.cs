using System;
using System.Text.RegularExpressions;
class Program
{
    static void Main(string[] args)
    {
        MatchCollection results
            = Regex.Matches(Console.ReadLine(), "[A|T|C|G]+");
        int length = 0;
        foreach (Match m in results)
        {
            if (m.Value.Length > length)
                length = m.Value.Length;
        }
        Console.WriteLine(length);
        Console.Read();
    }
}