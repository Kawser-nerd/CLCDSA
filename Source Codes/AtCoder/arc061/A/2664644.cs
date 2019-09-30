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
            var str = Console.ReadLine();
            var strar = str.Select(_ => int.Parse(_.ToString())).ToList();
            var len = str.Length;
            var bits = new List<List<bool>>();
            if (len == 1)
            {
                Console.WriteLine(str);
                return;
            }
            var x = CreateBits(bits, len - 1,0);
            long valls = 0;
            foreach (var item in x)
            {
                var count = bits.Count;
                long val = 0;
                var before = "";
                for (int i = 0; i < len; i++)
                {
                    if (i < len - 1)
                    {
                        if (item[i])
                        {
                            before += strar[i];
                        }
                        else
                        {
                            before += strar[i];
                            val += long.Parse(before);
                            before = "";
                        }
                    }
                    else
                    {
                        if (before == "")
                            val += strar[i];
                        else
                        {
                            val += long.Parse((before + strar[i]));
                        }
                    }
                }
                valls += val;
            }

            Console.WriteLine(valls);
            Console.ReadLine();

        }

        private static List<List<bool>> CreateBits(List<List<bool>> bits, int len, int count)
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
                return CreateBits(bits, len, count);
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
             return CreateBits(ls, len, count);
        }
    }
}