using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace AtCoder
{
    class Pair
    {
        public int num;
        public int count;
    }

    class Program
    {
        static void Main()
        {
            //????
            int[] str = ReadLineToIntArray();
            int N = str[0];
            int M = str[1];
            int X = str[2];
            int Y = str[3];

            int[] x = ReadLineToIntArray();
            int[] y = ReadLineToIntArray();

            string ans = "War";

            for(int Z = X + 1; Z <= Y; Z++)
            {
                bool flag = true;
                for(int i = 0; i < N; i++)
                {
                    if (x[i] >= Z)
                    {
                        flag = false;
                        break;
                    }
                }
                for(int i = 0; i < M; i++)
                {
                    if (y[i] < Z)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == true)
                {
                    ans = "No War";
                    break;
                }
            }

            //????
            Console.WriteLine(ans);
            Console.ReadKey();
        }

        long mod = 1000000007;
        static public void Swap<T>(ref T a,ref T b) { T temp = a;a = b;b = temp; }
        static public long GCD(int a, int b){ return b != 0 ? GCD(b, a % b) : a;}
        static public long LCM(int a, int b){ return (long)a * b / GCD(a, b); }
        static public int Factorial(int a) { return a == 1 ? a : a * Factorial(a - 1); }
        static public int Conbin(int n,int m) { return Factorial(n) / (Factorial(n - m) * Factorial(m)); }


        
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