using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var bits = CreateBits(n);
            var ls = new List<int>();
            var val = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                ls.Add(int.Parse(Console.ReadLine()));
            }
            foreach (var item in bits)
            {
                var v1 = 0;
                var v2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (item[i])
                        v1 += ls[i];
                    else
                        v2 += ls[i];
                }
                var m = v1 >= v2 ? v1 : v2;
                if (m < val)
                    val = m;

            }
            Console.WriteLine(val);
            Console.ReadLine();
        }

        /// <summary>
        /// Bit??????????
        /// </summary>
        /// <param name="len">???????(len?0???????)</param>
        /// <returns>?????</returns>
        public static List<List<bool>> CreateBits(int len)
        {
            return CreateBitsPri(new List<List<bool>>(), len, 0);
        }

        private static List<List<bool>> CreateBitsPri(List<List<bool>> bits, int len, int count)
        {
            if (count == 0)
            {
                var lss = new List<bool>();
                lss.Add(true);
                bits.Add(lss);
                var lx = new List<bool>();
                lx.Add(false);
                bits.Add(lx);
                count++;
                return CreateBitsPri(bits, len, count);
            }
            if (len - count == 0)
                return bits;
            count++;
            var ls = new List<List<bool>>();
            foreach (var item in bits)
            {
                var x = item.ToList();
                x.Add(true);
                item.Add(false);
                ls.Add(item);
                ls.Add(x);
            }
            return CreateBitsPri(ls, len, count);
        }
    }
}