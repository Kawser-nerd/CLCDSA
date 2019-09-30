using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//F(A,B)??????????????????????
//?Sqrt(X)???????????A??????
namespace ABC_C
{
    class C057
    {
        //??????????????????????????????)
        public static List<int> GetOrders(long value)
        {
            List<int> list = new List<int>();
            long x = value;
            while (x > 0)
            {
                list.Add((int)(x % 10));
                x /= 10;
            }
            return list;
        }

        //10???
        public static int GetNumberOfDigits(long value)
        {
            return GetOrders(value).Count;
        }

        //????????O(?n)
        public static List<long> GetAllDivisors(long x)
        {
            long sx = (long)Math.Sqrt(x);
            List<long> list = new List<long>();
            for (int n = 1; n <= sx; n++)
            {
                if (x % n == 0)
                {
                    long m = x / n;
                    list.Add(n);
                    if (n != m) list.Add(m);
                }
            }
            list.Sort();
            return list;
        }


        static void Main(string[] args)
        {
            long X = long.Parse(Console.ReadLine());

            List<long> divisors = GetAllDivisors(X);
            int i;
            for(i = 0; i < divisors.Count; i++)
            {
                if (divisors[i] >= Math.Sqrt(X)) break;
            }
            long A = divisors[i]; long B = X / A;
            int z = Math.Max(GetNumberOfDigits(A), GetNumberOfDigits(B));
            Console.WriteLine(z);
        }
    }
}