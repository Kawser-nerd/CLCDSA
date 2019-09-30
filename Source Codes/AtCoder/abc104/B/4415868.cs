using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        if (s.Substring(0, 1) == "A" && char.IsLower(s[1]))
        {
            var buf = s.Substring(2).ToCharArray();
            if (buf.Last() != 'C' && buf.Where(x => x == 'C').Count() == 1)
            {
                if (buf.Where(x => x != 'C').All(x => char.IsLower(x)))
                {
                    Console.WriteLine("AC");
                    return;
                }
            }
        }

        Console.WriteLine("WA");
    }
}