using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

class Program
{
    static void Main(string[] args)
    {
        int cases = int.Parse(Console.ReadLine());

        for(int c=0; c<cases; c++) {
            string[] line = Console.ReadLine().Split(' ');

            int N = int.Parse(line[0]);
            BigInteger[] v = new BigInteger[N];
            for(int i=1; i<line.Length; i++) v[i-1] = BigInteger.Parse(line[i]);

            Array.Sort(v);

            BigInteger g = v[1] - v[0];
            for(int i=2; i<N; i++) {
                g = BigInteger.GreatestCommonDivisor(g, v[i] - v[0]);
            }

            BigInteger rem = (g-v[v.Length-1] % g) % g;

            Console.WriteLine("Case #{0}: {1}", c + 1, rem);
        }    
    }
}
