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
            var xx = Console.ReadLine()
                .Split(' ')
                .Select(x => int.Parse(x))
                .ToArray();

            var n = xx[0];
            var m = xx[1];
            var bits = CreateBits(n);
            var ls = new List<KeyValuePair<int, int>>();
            for (int i = 0; i < m; i++)
            {
                var str = Console.ReadLine()
                    .Split(' ')
                    .Select(x => int.Parse(x))
                    .ToArray();
                var x1 = str[0];
                var y1 = str[1];
                ls.Add(new KeyValuePair<int, int>(x1, y1));
            }
            var value = 1;
            foreach (var item in bits)
            {
                var isOk = true;

                var length = item.Count;
                for (int i = 0; i < length; i++)
                {
                    if (item[i])
                    {
                        for (int j = 0; j < length; j++)
                        {
                            if (i == j)
                                continue;
                            if (item[j])
                            {
                                if (!(ls.Contains(new KeyValuePair<int, int>(i + 1, j + 1)) || ls.Contains(new KeyValuePair<int, int>(j + 1,i + 1))))
                                {
                                    isOk = false;
                                    break;
                                }
                            }
                        }
                    }
                    if (!isOk)
                    {
                        break;
                    }
                }
                if (isOk)
                {
                    var num = item.Count(x => x == true);
                    if (num > value)
                        value = num;
                }

            }
            Console.WriteLine(value);
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