using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            //????
            int[] pos = IO.ReadLineToIntArray();

            int[] ans = new int[4];

            double kakudo = Math.Atan2(pos[3] - pos[1], pos[2] - pos[0]);
            double len = Math.Sqrt(Math.Pow(pos[3] - pos[1], 2) + Math.Pow(pos[2] - pos[0], 2));
            ans[0] = (int)Math.Round(pos[0] + len * Math.Sqrt(2.0) * Math.Cos(kakudo + Math.PI/4));
            ans[1] = (int)Math.Round(pos[1] + len * Math.Sqrt(2.0) * Math.Sin(kakudo + Math.PI/4));
            ans[2] = (int)Math.Round(pos[0] + len * Math.Cos(kakudo + Math.PI/2));
            ans[3] = (int)Math.Round(pos[1] + len * Math.Sin(kakudo + Math.PI/2));

            //????
            Console.WriteLine(ans[0]+" "+ans[1]+" "+ans[2]+" "+ans[3]);
            Console.ReadKey();
        }
    }
    
    class Func
    {
        long mod = 1000000007;
        static public void Swap<T>(ref T a, ref T b) { T temp = a; a = b; b = temp; }
        static public long GCD(int a, int b) { return b != 0 ? GCD(b, a % b) : a; }
        static public long LCM(int a, int b) { return (long)a * b / GCD(a, b); }
        static public int Factorial(int a) { return a == 1 ? a : a * Factorial(a - 1); }
        static public int Conbin(int n, int m) { return Factorial(n) / (Factorial(n - m) * Factorial(m)); }
        static public void Factoring(long num, ref long[] vs)
        {
            if (num == 1)
            {
                vs[1]++;
            }
            for (long i = 2; i < (long)Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    vs[i]++;
                    Factoring(num / i, ref vs);
                }
            }
            vs[1]++;
        }
    }

    class IO
    {
        static public string ReadLineToString(){return Console.ReadLine();}
        static public int ReadLineToInt(){return int.Parse(Console.ReadLine());}
        static public long ReadLineToLong() { return long.Parse(Console.ReadLine()); }
        static public string[] ReadLineToStringArray(){return Console.ReadLine().Split(' ').ToArray();}
        static public int[] ReadLineToIntArray(){return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();}
        static public long[] ReadLineToLongArray() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
        static public List<string> ReadLineToStringList(){return Console.ReadLine().Split(' ').ToList();}
        static public List<int> ReadLineToIntList(){return Console.ReadLine().Split(' ').Select(int.Parse).ToList();}
        static public List<long> ReadLineToLongList() { return Console.ReadLine().Split(' ').Select(long.Parse).ToList(); }   
    }
}