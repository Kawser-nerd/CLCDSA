using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        char[] s;
        int count = 0;
        for (int i = 0; i < 12; i++)
        {
            s = Console.ReadLine().ToCharArray();
            if (s.Any(a => a == 'r'))
                count++;
        }
        Console.WriteLine(count);
    }
}