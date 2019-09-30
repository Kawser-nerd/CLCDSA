using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Solution
{
    class sol2
    {
        #region
        List<String> res = new List<string>();
        String[] strs;
        public void main()
        {
            strs = File.ReadAllLines("C:\\GCJ\\Solution\\Solution\\bin\\files\\in.in");
            solve();
            print();
        }

        void print()
        {
            List<string> result = new List<string>();
            for (int i = 0; i < res.Count; i++)
            {
                result.Add(("Case #" + (i + 1).ToString() + ": " + res[i]).Replace(',', '.'));
            }
            File.WriteAllLines("out.out", result.ToArray());
        }
        #endregion

        struct Coords
        {
            public int x;
            public int y;
            public int r;
        }

        void solve()
        {
            int n = int.Parse(strs[0]);
            int num = 1;
            for (int i = 0; i < n; i++)
            {
                int k = int.Parse(strs[num]);
                num++;
                List<Coords> coords = new List<Coords>();
                for (int l = 0; l < k; l++)
                {
                    Coords coord = new Coords();
                    coord.x = int.Parse(strs[num].Split(' ')[0]);
                    coord.y = int.Parse(strs[num].Split(' ')[1]);
                    coord.r = int.Parse(strs[num].Split(' ')[2]);
                    coords.Add(coord);
                    num++;
                }
                if (coords.Count == 1)
                {
                    res.Add(coords[0].r.ToString());
                }
                if (coords.Count == 2)
                {
                    res.Add(Math.Max(coords[0].r, coords[1].r).ToString());
                }
                if (coords.Count == 3)
                {
                    double res1 = Math.Max(coords[0].r, (coords[1].r + coords[2].r) /2.0 + 
                        Math.Sqrt((coords[1].x - coords[2].x) * (coords[1].x - coords[2].x) +
                        (coords[1].y - coords[2].y) * (coords[1].y - coords[2].y)) / 2.0);
                    double res2 = Math.Max(coords[1].r, (coords[0].r + coords[2].r) / 2.0 +
                        Math.Sqrt((coords[0].x - coords[2].x) * (coords[0].x - coords[2].x) +
                        (coords[0].y - coords[2].y) * (coords[0].y - coords[2].y)) / 2.0);
                    double res3 = Math.Max(coords[2].r, (coords[0].r + coords[1].r) / 2.0 +
                        Math.Sqrt((coords[0].x - coords[1].x) * (coords[0].x - coords[1].x) +
                        (coords[1].y - coords[0].y) * (coords[1].y - coords[0].y)) / 2.0);
                    res.Add(Math.Min(res1, Math.Min(res2, res3)).ToString());
                }
            }
        }
    }
}
