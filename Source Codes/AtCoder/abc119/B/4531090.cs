using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Otoshidama
    {
        public double value;
        public string type;
        public double sum
        {
            get
            {
                if (type == "BTC")
                {
                    return value * 380000.0;
                }
                else
                {
                    return value;
                }
            }
        }
    }

    class Program
    {

        static void Main()
        {
            //????


            int N = ReadLineToInt();
            Otoshidama[] otoshidamas = new Otoshidama[N];
            double ans = 0;

            for(int i = 0; i < N; i++)
            {
                string[] temp = Console.ReadLine().Split();
                Otoshidama otoshidama = new Otoshidama();
                otoshidama.value = double.Parse( temp[0]);
                otoshidama.type = temp[1];
                ans += otoshidama.sum;
            }

            //????


            Console.WriteLine(ans);
            Console.ReadKey();
        }


        static public void Swap<T>(ref T a,ref T b) { T temp = a;a = b;b = temp; }
        static public long GCD(int a, int b){ return b != 0 ? GCD(b, a % b) : a;}
        static public long LCM(int a, int b){ return (long)a * b / GCD(a, b); }



        
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