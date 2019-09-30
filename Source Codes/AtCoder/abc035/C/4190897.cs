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
        var inputs = Console.ReadLine().Split();
        int len = int.Parse(inputs[0]);
        int n = int.Parse(inputs[1]);
        int[] imos = new int[len + 1];
        foreach(int i in Enumerable.Range(0, n))
        {
            inputs = Console.ReadLine().Split();
            int start = int.Parse(inputs[0]) - 1;
            int end = int.Parse(inputs[1]);
            imos[start]++;
            imos[end]--;
        }
        foreach(int i in imos.Select((x, index) => index).Skip(1))
        {
            imos[i] += imos[i - 1];
        }
        Console.WriteLine(string.Join("", imos.Take(len).Select(x => (x & 1) == 0 ? 0 : 1)));
    }

    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}