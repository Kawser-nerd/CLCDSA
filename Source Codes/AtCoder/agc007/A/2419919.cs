using System.Collections.Generic;
using System.Linq;
using System;

public class P
{
    public int x { get; set; }
    public int y { get; set; }
    public string via { get; set; }
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var map = new bool[h, w];
        for (int i = 0; i < h; i++)
        {
            var s =Console.ReadLine().Trim();
            for (int j = 0; j < w; j++)
                if (s[j] == '#') map[i, j] = true;
        }
        Console.WriteLine(goDfs(map) ? "Possible": "Impossible");
    }
    public static bool   goDfs (bool[,] map)
    {
        var h = map.GetLength(0);
        var w = map.GetLength(1);
      var st = new Queue<P>();
        st.Enqueue(new P { x = 0, y = 0, via = "" });
        while (st.Count() > 0)
        {
            var t = st.Dequeue();
            if (t.x == h - 1 && t.y == w - 1 && checkVia(map, t.via)) return true;
         if (t.y + 1 < w && map[t.x, t.y +1] )  st.Enqueue(new P { x = t.x, y = t.y + 1, via = t.via + "r" });
            if (t.x + 1 < h && map[t.x+1, t.y ]) st.Enqueue(new P { x = t.x+1, y = t.y , via = t.via + "d" });
        }
        return false;   
    }
    public static bool checkVia (bool [,] map , string a)
    {
        var h = map.GetLength(0);
        var w = map.GetLength(1);
        var map2 = new bool[h, w];
        var x = 0;  var y = 0;  map2[0, 0] = true;
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] == 'r') y++;
            else x++;
            map2[x, y] = true;
        }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (map[i, j] != map2[i, j]) return false;
        return true;
    }
}