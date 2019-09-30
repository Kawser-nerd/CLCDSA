using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static int[] Swap(int[] src, int[] change)
    {
        return
            change.Select(x => src[x]).ToArray();
    }
    public void Slove()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);        
        int m = int.Parse(inputs[1]);
        int[] result = Enumerable.Range(1, n).ToArray();
        if(m == 0)
        {
            Console.WriteLine(string.Join("\n", result));
            return;
        }
        int d = int.Parse(inputs[2]);
        int log = (int)Math.Log(d, 2);
        int[] amida = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] swap = Enumerable.Range(0, n).ToArray();
        foreach(int i in amida)
        {
            int temp = swap[i - 1];
            swap[i - 1] = swap[i];
            swap[i] = temp;
        }
        if((d & 1) == 1)
            result = Swap(result, swap);
        d >>= 1;
        foreach(int i in Enumerable.Range(1, log))
        {
            swap = Swap(swap, swap);
            if((d & 1) == 1)
                result = Swap(result, swap);
            d >>= 1;
        }
        result = Enumerable.Range(1, n).OrderBy(x => result[x - 1]).ToArray();

        Console.WriteLine(string.Join("\n", result));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}