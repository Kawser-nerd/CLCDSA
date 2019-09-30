using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{     
    public Program()
    {
        Console.WriteLine(Slove());
    }
    static string Slove()
    {      
        int n = int.Parse(Console.ReadLine());
        int[][] data = 
            Enumerable.Range(0, n)
            .Select(x => 
                Console.ReadLine().Split('-').Select(int.Parse).ToArray()
            )
            .Select(x => new int[] { x[0] / 5 * 5, x[1] % 100 > 55 ? (x[1] / 100 + 1) * 100 : (x[1] + 4) / 5 * 5})
            .OrderBy(x => x[0])
            .ToArray();
        List<string> result = new List<string>();
        for(int i = 0, start = data[0][0], stop = data[0][1]; i < n; i++)
        {
            if(stop >= data[i][0])
            {
                stop = Math.Max(stop, data[i][1]);
            }
            else
            {
                result.Add($"{start:D4}-{stop:D4}");
                start = data[i][0];
                stop = data[i][1];
            }
            if(i == n - 1)
            {
                result.Add($"{start:D4}-{stop:D4}");
            }
        }
        return string.Join("\n", result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}