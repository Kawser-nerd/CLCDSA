using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        List<Tuple<int, int, int>> Table = new List<Tuple<int ,int, int>>() { Capacity = M };
        for(int i = 0; i < M; i++)
        {
            str = Console.ReadLine().Split(' ');
            Tuple<int, int, int> t = new Tuple<int, int, int>(i, int.Parse(str[0]), int.Parse(str[1]));
            Table.Add(t);
        }
        Table.Sort((x,y)=>
        {
            if (x.Item2 - y.Item2 != 0)
                return x.Item2 - y.Item2;
            else
                return x.Item3 - y.Item3;
        });
        int pref = Table[0].Item2;
        int tid = 1;
        List<Tuple<int, string>> Table2 = new List<Tuple<int, string>>();
        for (int i = 0; i < M; i++)
        {
            if(pref == Table[i].Item2)
            {
                Table2.Add(new Tuple<int, string>(Table[i].Item1, pref.ToString().PadLeft(6, '0') + tid.ToString().PadLeft(6,'0')));
                tid++;
            }
            else
            {
                pref = Table[i].Item2;
                tid = 1;
                Table2.Add(new Tuple<int, string>(Table[i].Item1, pref.ToString().PadLeft(6, '0') + tid.ToString().PadLeft(6, '0')));
                tid++;
            }
        }
        Table2.Sort((x, y) => x.Item1 - y.Item1);
        foreach (var i in Table2)
            Console.WriteLine(i.Item2);
    }
}