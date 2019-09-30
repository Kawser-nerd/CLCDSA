using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var array = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var nums = new List<Number>();
        for (int i = 0; i < N; i++)
        {
            nums.Add(new Number(i, array[i]));
        }
        var sorted = nums.OrderByDescending(x => x.Value).ToArray();
        for (int i = 0; i < N; i++)
        {
            var isFormer = array[i] > sorted[(N + 1) / 2].Value;
            if (isFormer)
            {
                Console.WriteLine(sorted[(N + 1) / 2].Value);
            }
            else
                Console.WriteLine(sorted[(N + 1) / 2-1].Value);
            
        }
    }
}
public struct Number
{
    public Number(int index, int value)
    {
        Index = index;
        Value = value;
    }
    public int Index, Value;
}