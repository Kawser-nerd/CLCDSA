using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var colCount = int.Parse(Console.ReadLine());
        var array1 = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var array2 = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int max = array1[0] + array2.Sum();
        int tmp = max;
        for (int col = 1; col < colCount; ++col)
        {
            tmp += array1[col] - array2[col - 1];
            max = Math.Max(max, tmp);
        }
        Console.WriteLine(max);
    }
}