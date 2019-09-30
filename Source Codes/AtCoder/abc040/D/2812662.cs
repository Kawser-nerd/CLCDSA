using System.Linq;
using System;

public class UnionFind
{
    private int[] data;
    public UnionFind(int size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = -1;
    }
    public bool Union(int x, int y)
    {
        x = Root(x);
        y = Root(y);
        if (x != y)
        {
            if (data[y] < data[x])
            {
                var tmp = y;
                y = x;
                x = tmp;
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    public bool IsSameGroup(int x, int y) => Root(x) == Root(y);
    public int getMem(int root) => -data[root];
    public int Root(int x) => data[x] < 0 ? x : data[x] = Root(data[x]);
}

public class AA
{
    public int a { get; set; }
    public int b { get; set; }
    public int yy { get; set; }
}

public class Q
{
    public int id { get; set; }
    public int node { get; set; }
    public int yy { get; set; }
    public int ans { get; set; }
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var aa2 = new AA[m];
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]);
            var b = int.Parse(line[1]);
            var yy = int.Parse(line[2]);
            aa2[i] = new AA { a = a, b = b, yy = yy };
        }
        var aa = aa2.OrderByDescending(x => x.yy).ToArray();
        var q = int.Parse(Console.ReadLine().Trim());
        var qs2 = new Q[q];
        for (int i = 0; i < q; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var node = int.Parse(line[0]);
            var yy = int.Parse(line[1]);
            qs2[i] = new Q { id = i, node = node, yy = yy };
        }
        var qs = qs2.OrderByDescending(x => x.yy).ToArray();
        getAns(aa, qs, n);
    }
    public static  void  getAns (AA[] aa, Q[] qs , int n )
    {
        var qL = qs.Length;
        var aaL = aa.Length;
        var uf = new UnionFind(n + 10);
        var p = 0;  var p1 = 0;
        while (p1 <qL)
        {
            if ( p < aaL  && aa[p].yy > qs[p1].yy) { uf.Union(aa[p].a, aa[p++].b);  continue; }
            var r1 = uf.Root(qs[p1].node);
            qs[p1++].ans = uf.getMem(r1);
        }
        foreach (var x in qs.OrderBy(y =>y.id))
            Console.WriteLine(x.ans);
    }
}