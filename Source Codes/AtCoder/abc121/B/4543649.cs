using System;
using System.Collections.Generic;
using System.Linq;

// AtCorder??Template
namespace Atcoder{
    public class main{

        // ?????????
        static string readString(){return Console.ReadLine();}
        static int readInteger(){return int.Parse(Console.ReadLine());}
        static long readLong(){return long.Parse(Console.ReadLine());}
        static double readDouble(){return double.Parse(Console.ReadLine());}
        static decimal readDecimal(){return decimal.Parse(Console.ReadLine());}

        static List<char> readCharL(char separator=' '){return Console.ReadLine().Split(separator).Select((x) => Convert.ToChar(x)).ToList();}
        static List<string> readStringL(char separator=' '){return Console.ReadLine().Split(separator).ToList();}
        static List<int> readIntegerL(char separator=' '){return Console.ReadLine().Split(separator).Select((x) => int.Parse(x)).ToList();}

        static void print<T>(T args){Console.WriteLine(args);}
        static void printL<T>(List<T> _list){Console.WriteLine(string.Join(",", _list));}

        public static void Main(string[] args)
        {
            var tmp = readIntegerL();
            int N = tmp[0];
            int M = tmp[1];
            int C = tmp[2];
            var B = readIntegerL();

            int counter = 0;

            foreach(var i in Enumerable.Range(0, N))
            {
                var sum = 0;
                var _list = readIntegerL();
                for(var j = 0; B.Count() > j; j++)
                {
                    var tmp2 = _list[j] * B[j];
                    sum += tmp2;
                }
                if((sum + C) > 0)
                {
                    counter++;
                }
            }
            Console.WriteLine(counter);
        }
    }
}