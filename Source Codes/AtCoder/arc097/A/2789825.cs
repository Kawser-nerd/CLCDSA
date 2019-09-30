using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var line = Console.ReadLine();
        var N = int.Parse(Console.ReadLine());
        HashSet<string> subStrings = new HashSet<string>();
        for (int i = 0; i < line.Length; i++)
        {
            string str = "";
            for (int j = i; j < Math.Min(i+N,line.Length); j++)
            {
                str = string.Concat(str, line[j].ToString());
                subStrings.Add(str);
            }
        }
        Console.WriteLine(string.Join("\n",subStrings.OrderBy(x=>x).ToArray()[N-1]));
    }
}