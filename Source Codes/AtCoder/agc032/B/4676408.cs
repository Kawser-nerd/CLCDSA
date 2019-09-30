using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace AtCoder
{
    class B
    {
        public int index;
        public int num;
    }

    class Program
    {
        static void Main()
        {
            //????
            int N = IO.ReadLineToInt();
            int M = N % 2 == 0 ? (N - 2) * N / 2 : (N - 1) * (N - 1) / 2;
            int S = N % 2 == 0 ? (N + 1) * (N / 2 - 1) : N * (N / 2);

            List<Tuple<int, int>> ans = new List<Tuple<int, int>>();

            if (N % 2 == 0)
            {
                for(int i = 1; i <= N; i++)
                {
                    for(int j = i + 1; j <= N; j++)
                    {
                        if (i + j != N + 1)
                        {
                            ans.Add(new Tuple<int, int>(i,j));
                        }
                    }
                }
            }
            else
            {
                for (int i = 1; i < N; i++)
                {
                    for (int j = i + 1; j <= N; j++)
                    {
                        if (i + j != N )
                        {
                            ans.Add(new Tuple<int, int>(i, j));
                        }
                    }
                }
            }

            Console.WriteLine(M);
            for(int i = 0; i < M; i++)
            {
                Console.WriteLine(ans[i].Item1 + " " + ans[i].Item2);
            }

            //????
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