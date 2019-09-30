using System; 
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        Console.WriteLine(s.Length / 2 - s.Count(x => x == 'p'));
    }
}