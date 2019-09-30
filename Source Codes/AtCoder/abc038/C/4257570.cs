using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static IEnumerable<int> IncreaseCount(int[] src)
    {
        int bef = 0;
        int count = 0;
        foreach(int num in src)
        {
            if(bef < num)
                count++;
            else
            {
                yield return count;
                count = 1;
            }
            bef = num;
        }
        yield return count;
    }
    public void slove()
    {
        int n = int.Parse(Console.ReadLine());
        var array =
            Console.ReadLine().Split()
            .Select(int.Parse)
            .ToArray();
        long result =
            IncreaseCount(array)
            //.Select(x => {System.Console.WriteLine(x); return x;})
            .Select(x => (long)(1 + x) * x / 2)
            .Sum();
        System.Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}