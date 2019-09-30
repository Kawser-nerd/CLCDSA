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
            int[] temp = IO.ReadLineToIntArray();

            List <B> bs = new List<B>();
            int nowLen = N;

            for (int i = 0; i < N; i++)
            {
                B b = new B
                {
                    index = i + 1,
                    num = temp[i]
                };
                bs.Add(b);
            }

            List<int> ans = new List<int>();
            bool flag = false;

            while (bs[0].num == 1)
            {
                B last = bs.Last(b => b.index == b.num);
                ans.Add(last.num);
                bs.RemoveAt(last.index - 1);
                nowLen--;

                if (bs.Count == 0)
                {
                    flag = true;
                    break;
                }

                for(int i = last.index - 1; i < nowLen;i++)
                {
                    bs[i].index--;
                }
            }

            if (!flag)
            {
                Console.WriteLine(-1);
                return;
            }

            ans.Reverse();
            foreach(var a in ans)
            {
                Console.WriteLine(a);
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