using System;
using System.Linq;
 
namespace arc024_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] lshoes = new int[50];
            int[] rshoes = new int[50];
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] l = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] r = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int i = 0; i < x[0]; i++)
            {
                lshoes[l[i]]++;
            }
            for (int i = 0; i < x[1]; i++)
            {
                rshoes[r[i]]++;
            }
            int ret = 0;
            for (int i = 10; i <= 40; i++)
            {
                ret += Math.Min(lshoes[i], rshoes[i]);
            }
            Console.WriteLine(ret);
        }
    }
}