using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            var AB_Array = new List<TwoInt>();
            string[] n_m = Console.ReadLine().Split(' ');
            int n = int.Parse(n_m[0]);
            int m = int.Parse(n_m[1]);

            //???????
            for (var i = 0; i < n; i++)
            {
                string[] A_B = Console.ReadLine().Split(' ');

                int a = int.Parse(A_B[0]);
                int b = int.Parse(A_B[1]);
                var ab = new TwoInt(a, b);
                AB_Array.Add(ab);
            }
            //?????
            AB_Array = SortTwoIntList(AB_Array);

            //foreach(var rec in AB_Array)
            //{
            //    Console.WriteLine($"{rec.A},{rec.B}");
            //}

            //????
            long totalPrice = 0;
            for (var i = 0; i < n; i++)
            {
                if (m - AB_Array[i].B >= 0)
                {
                    m -= AB_Array[i].B;
                    totalPrice += (long)AB_Array[i].A * (long)AB_Array[i].B;
                }
                else
                {
                    totalPrice += (long)AB_Array[i].A * (long)m;
                    break;
                }
            }
            Console.WriteLine(totalPrice);
        }
        static List<TwoInt> SortTwoIntList(List<TwoInt> list)
        {
            IOrderedEnumerable<TwoInt> sortList =
                list.OrderBy(rec => rec.A).ThenBy(rec => rec.B);

            List<TwoInt> returnValue = sortList.ToList();

            return returnValue;
        }



    }

    class TwoInt
    {
        public int A;
        public int B;

        public TwoInt(int A, int B)
        {
            this.A = A;
            this.B = B;
        }
    }
}