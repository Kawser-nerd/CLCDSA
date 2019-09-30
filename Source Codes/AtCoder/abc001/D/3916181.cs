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
        List<string> result = new List<string>();
        int[] times = new int[24 * 12 + 1];
        foreach(int i in Enumerable.Range(0, n))
        {
            int[] inputs = Console.ReadLine().Split('-')
                .Select(int.Parse)
                .Select(x => x % 100 + x / 100 * 60)
                .Select((x, index) => (x + 4 * index) / 5)
                .ToArray();
            times[inputs[0]] += 1;
            times[inputs[1]] -= 1;
        }
        foreach(int t in Enumerable.Range(1, times.Length - 1))
            times[t] += times[t - 1];
        for(int i = 0, start = -1; i < times.Length; i++)
        {
            if(start == -1 && times[i] > 0)
            {
                start = i;
            }
            else if(start >= 0 && (i == times.Length - 1 || times[i] == 0))
            {
                //Console.WriteLine(start);
                result.Add($"{start / 12:D2}{start % 12 * 5:D2}-{i / 12:D2}{i % 12 * 5:D2}");
                start = -1;
            }
        }

        return string.Join("\n", result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}