using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


class Program
{
    public void Slove()
    {    
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        int[] array = 
            Enumerable.Range(0, n)
            .Select(x => int.Parse(Console.ReadLine()))
            .ToArray();
        if(array.Any(x => x == 0))
        {
            Console.WriteLine(n);
            return;
        }
        int maxCount = 0;
        long product = 1;
        for(int start = 0, end = 0; end < n; end++)
        {
            product *= array[end];
            while(product > k && start <= end)
                product /= array[start++];
            //Console.WriteLine(start);
            maxCount = Math.Max(maxCount, end - start + 1);
        }
        Console.WriteLine(maxCount);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}