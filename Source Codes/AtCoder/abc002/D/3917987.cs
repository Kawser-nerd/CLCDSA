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
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = inputs[0];
        int m = inputs[1];
        bool[][] parents = Enumerable.Range(0, n).Select(x => new bool[n]).ToArray();
        foreach(int i in Enumerable.Range(0 , n))
            parents[i][i] = true;
        foreach(int i in Enumerable.Range(0 , m))
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).Select(x => x - 1).ToArray();
            parents[inputs[0]][inputs[1]] = true;
            parents[inputs[1]][inputs[0]] = true;
        }
        int max = 0;
        foreach(int i in Enumerable.Range(0, 1 << n))
        {
                //Console.WriteLine(Convert.ToString(i, 2));
            if(parents
                .Where((x ,index) => (i >> index & 1) == 1)
                .All(x => x
                    .Where((y ,index) => (i >> index & 1) == 1)
                    .All(y => y)))
            {
                max = Math.Max(max, Convert.ToString(i, 2).Count(x => x == '1'));
            }
        }
        Console.WriteLine(max);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}