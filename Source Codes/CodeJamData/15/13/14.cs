using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        public static long Cha(Tuple<long, long> b, Tuple<long, long> c, Tuple<long, long> a)
        {
            return (b.Item1 - a.Item1) * (c.Item2 - a.Item2) - (b.Item2 - a.Item2) * (c.Item1 - a.Item1);
        }

        public static List<int> Get(List<Tuple<long,long>> pList)
        {
            var list = new List<int>();
            for (int i = 0; i < pList.Count(); i++)
            {
                int ans = pList.Count() > 2 ? pList.Count() - 2 : 0;
                for (int j = 0; j < pList.Count(); j++)
                { 
                    if(j==i)
                        continue;
                    int num = 0;
                    for (int k = 0; k < pList.Count(); k++)
                    {
                        if (k == j || k == i)
                            continue;
                        if (Cha(pList[j], pList[k], pList[i]) < 0)
                            num++;
                    }
                    ans = Math.Min(ans, num);
                }
                list.Add(ans);
            }
            return list;
        }


        static void Main(string[] args)
        {
            var lines = System.IO.File.ReadAllLines(@"C:\Users\Vivian\Downloads\C-small-attempt1.in");
            using (var sw = new StreamWriter("output.txt"))
            {
                int num = int.Parse(lines[0]);
                int cur = 1;
                for (int i = 1; i <= num; i++)
                {
                    int n = int.Parse(lines[cur]);
                    List<Tuple<long, long>> list = new List<Tuple<long, long>>();
                    cur++;
                    while (n-- > 0)
                    {
                        var arr = lines[cur].Split(' ').Select(long.Parse).ToArray();
                        list.Add(new Tuple<long, long>(arr[0], arr[1]));
                        cur++;
                    }
                    sw.WriteLine("Case #{0}:", i);
                    var clist = Get(list);
                    foreach (var c in clist)
                        sw.WriteLine(c);
                }
            }
        }
    }
}
