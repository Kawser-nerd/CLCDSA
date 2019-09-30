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

            string S = ReadLineToString();
            string T = ReadLineToString();

            int [] charS = new int[26];
            int [] charT = new int[26];

            for(int i = 0; i < 26; i++)
            {
                charS[i] = 0;
                charT[i] = 0;
            }

            for (int i = 0; i < S.Length; i++)
            {
                charS[char.Parse(S.Substring(i, 1)) - 97]++;
                charT[char.Parse(T.Substring(i, 1)) - 97]++;
            }

            charS = charS.OrderByDescending(c => c).ToArray();
            charT = charT.OrderByDescending(c => c).ToArray();

            string ans = "Yes";

            for(int i = 0; i < 26; i++)
            {
                if (charS[i] != charT[i])
                {
                    ans = "No";
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