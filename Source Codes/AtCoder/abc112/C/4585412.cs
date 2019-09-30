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
            int N = ReadLineToInt();
            long[][] point = new long[N][];
            for(int i = 0; i < N; i++)
            {
                long[] temp = ReadLineToLongArray();
                point[i] = temp;
            }

            point = point.OrderByDescending(p => p[2]).ToArray();

            long[] ans = new long[3];
            for(long x = 0; x < 101; x++)
            {
                for(long y = 0; y < 101; y++)
                {
                    long H = Math.Abs(point[0][0] - x) + Math.Abs(point[0][1] - y) + point[0][2];

                    bool flag = true;

                    for (int i = 0; i < N; i++)
                    {
                        if( point[i][2] != Math.Max( H - Math.Abs(point[i][0] - x) - Math.Abs(point[i][1] - y ), 0 ))
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (flag)
                    {
                        ans[0] = x;
                        ans[1] = y;
                        ans[2] = H;
                    }
                }
            }



            //????
            Console.WriteLine(ans[0]+" "+ans[1]+" "+ans[2]);
            Console.ReadKey();
        }


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