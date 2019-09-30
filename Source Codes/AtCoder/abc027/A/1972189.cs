using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<int, int>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        {
            for (int i = 0; i < 3; i++)
            {
                var w = int.Parse(line[i]);
                if (d.ContainsKey(w)) d[w]++;
                else d[w] = 1;
            }
            Console.WriteLine(d.Where(x => x.Value == 1 | x.Value == 3).First().Key);
        }
    }
}