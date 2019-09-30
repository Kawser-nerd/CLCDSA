using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    public void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();

        // dictRoad -- < ??,???????? > ?Dict
        // cityColorRoad-- ??????????

        var dictRoad = new Dictionary<int, List<int>>();
        for (int i = 0; i < N; i++) dictRoad.Add(i, new List<int>());

        for(int i = 0;i<M;i++)
        {
            int from = cin.nextInt() - 1;
            int to = cin.nextInt() - 1;

            dictRoad[from].Add(to);
            dictRoad[to].Add(from);
        }

        var cityColorRoad = new int[N];

        int colorRoad = 0;
        for (int i = 0; i < N; i++)
        {          
            if (cityColorRoad[i] == 0)
            {
                colorRoad++;
                cityColorRoad[i] = colorRoad;
                Paint(i, colorRoad, dictRoad, cityColorRoad);
            }
        }

        Console.WriteLine(colorRoad - 1);
        Console.Read();
    }

    void Paint(int i, int color, Dictionary<int, List<int>> dict, int[] cityColors)
    {
        List<int> list = dict[i];
        for (int j = 0; j < list.Count; j++)
        {
            int city = list[j];
            if (cityColors[city] == 0)
            {
                cityColors[city] = color;
                Paint(city, color, dict, cityColors);
            }
        }
    }
}


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}