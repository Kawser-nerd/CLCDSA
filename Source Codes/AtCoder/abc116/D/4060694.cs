using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace PaizaSkillCheck
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string[] line = Console.ReadLine().Split(' ');
            int n = int.Parse(line[0]);
            int k = int.Parse(line[1]);

            //  ??????
            ulong maxPoint = 0;

            //  ?????????????
            ulong nowPoint = 0;

            //  ?????????           
            int kindCount = 0;

            //  ???????
            Sushi[] topSushi = new Sushi[n + 1];

            //  ?????????
            List<Sushi> sushiList = new List<Sushi>(n);
            for (int i = 0; i < n; i++)
            {
                line = Console.ReadLine().Split(' ');
                int kind = int.Parse(line[0]);
                int point = int.Parse(line[1]);

                Sushi sushi = new Sushi(kind, point);

                topSushi[kind] = Sushi.Max(topSushi[kind], sushi);

                sushiList.Add(sushi);
            }
            //  ????????
            List<Sushi> selectList = sushiList.OrderByDescending(i => i.isFirst).OrderByDescending(i => i.point).Take(k).ToList();

            //  ???????????????????
            List<Sushi> isFirstList = topSushi.Where((a) => a != null).OrderByDescending(i => i.point).ToList();

            //  ?????
            selectList.Reverse();

            //  ??????
            Sushi[] unnecessary = new Sushi[k];
            int unnecessary_index = 0;
            foreach (Sushi sushi in selectList)
            {
                //  ?????????????????
                nowPoint += (ulong) sushi.point;

                //  ?????????????
                if (sushi.isFirst)
                {
                    kindCount++;
                }
                //  ???????????????
                else
                {
                    unnecessary[unnecessary_index] = sushi;
                    unnecessary_index++;
                }
            }
            unnecessary_index = 0;

            maxPoint = nowPoint + ((ulong) kindCount * (ulong) kindCount);

            for (int i = (kindCount + 1); i <= k; i++)
            {
                nowPoint -= (ulong) unnecessary[unnecessary_index].point;
                unnecessary_index++;

                if (isFirstList.Count < i)
                {
                    Console.WriteLine(maxPoint);
                    Console.ReadLine();
                    return;
                }
                nowPoint += (ulong) isFirstList[i - 1].point;

                maxPoint = Math.Max(maxPoint, nowPoint + ((ulong)i * (ulong)i));
            }

            Console.WriteLine(maxPoint);
            Console.ReadLine();
        }

        /// <summary>
        /// ????????
        /// </summary>
        public class Sushi : IComparable
        {
            public int kind;
            public int point;
            public bool isFirst;

            public Sushi(int kind, int point)
            {
                this.kind = kind;
                this.point = point;
            }

            public override string ToString()
            {
                return string.Format("Kind : {0}, Point : {1}", kind, point);
            }

            public int CompareTo(Object obj)
            {
                Sushi sushi = (Sushi) obj;

                return (sushi?.point ?? 0) - this.point;
            }

            public static Sushi Max(Sushi a, Sushi b)
            {
                if (a == null)
                {
                    if (b != null) b.isFirst = true;
                    return b;
                }
                if (b == null)
                {
                    if (a != null) a.isFirst = true;
                    return a;
                }

                bool largeA = (a.point > b.point);

                if(largeA)
                {
                    a.isFirst = true;
                    b.isFirst = false;

                    return a;
                }
                else
                {
                    a.isFirst = false;
                    b.isFirst = true;

                    return b;
                }
            }
        }
    }
}