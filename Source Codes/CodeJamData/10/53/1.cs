using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//PowerCollections library - http://powercollections.codeplex.com/
using Wintellect.PowerCollections;

namespace C
{
    class C
    {
        class Entry: IComparable
        {
            public int P, V;
            public Entry(int _P, int _V)
            {
                P = _P;
                V = _V;
            }

            public int CompareTo(object obj)
            {
                if (obj is Entry)
                {
                    Entry temp = (Entry)obj;

                    return (temp.V < V) ? -1 : (temp.V > V ? 1 : (temp.P < P?1:-1));
                }

                throw new ArgumentException("object is not a Temperature");
            }

        }


        static void Main(string[] args)
        {
            int T, C;
            T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                C = int.Parse(Console.ReadLine());
                List<Entry> list = new List<Entry>();
                SortedDictionary<int, Entry> dic = new SortedDictionary<int, Entry>();
                for (int j = 0; j < C; j++)
                {
                    string[] tmp = Console.ReadLine().Split(' ');
                    Entry e = new Entry(int.Parse(tmp[0]), int.Parse(tmp[1]));
                    dic.Add(e.P,e);
                    list.Add(e);
                }
                int wyn = 0;
                list.Sort();
                while (list[0].V > 1)
                {
                    wyn++;
                    Entry e = list[0];
                    e.V -= 2;
                    Entry down, up;
                    if (dic.ContainsKey(e.P-1))
                    {
                        down = dic[e.P - 1];
                        down.V++;
                    }
                    else
                    {
                        down = new Entry(e.P - 1, 1);
                        dic.Add(e.P - 1,down);
                        list.Add(down);
                    }
                   
                    if (dic.ContainsKey(e.P + 1))
                    {
                        up = dic[e.P + 1];
                        up.V++;
                    }
                    else
                    {
                        up = new Entry(e.P + 1, 1);
                        dic.Add(e.P + 1, up);
                        list.Add(up);
                    }
                    list.Sort();
                }
                
                Console.WriteLine("Case #" + i + ": " + wyn);
            }
        }
    }
}
