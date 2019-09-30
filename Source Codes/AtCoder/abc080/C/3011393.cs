using System;
using System.Linq;
using static System.Console;
using static System.Math;

namespace abc80_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[][] f = new int [n][];
            int[][] p = new int [n][];

            for(int i=0; i<n; i++){
                int[] tmp = ReadLine().Split().Select(int.Parse).ToArray();
                f[i] = tmp;
            }
            for(int i=0; i<n; i++){
                int[] tmp = ReadLine().Split().Select(int.Parse).ToArray();
                p[i] = tmp;
            }

            int max = int.MinValue;
            for(int i=1; i<(1<<10); i++){ //bit???
                int cc = 0;
                for(int j=0; j<n; j++){
                    int c=0;
                    for(int k=0; k<10; k++){
                        if( ((i>>k&1) == 1) && f[j][k] == 1) c++;
                    }
                    cc += p[j][c];
                }
                max = Max(max, cc);
            }
            WriteLine(max);
        }
    }
}