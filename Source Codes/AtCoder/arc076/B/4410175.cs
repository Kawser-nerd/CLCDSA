using System;
using System.Collections.Generic;
using System.Linq;
using UnionFind;

struct City
{
    public int id { get; private set; }
    public int x { get; private set; }
    public int y { get; private set; }

    public City(int id, int x, int y)
    {
        this.id = id;
        this.x = x;
        this.y = y;
    }
}

struct Edge
{
    public int a { get; private set; }
    public int b { get; private set; }
    public long cost { get; private set; }

    public Edge(int a, int b, long cost)
    {
        this.a = a;
        this.b = b;
        this.cost = cost;
    }
}

class Program
{
    static int N;
    static List<City> cities;
    static List<Edge> es;

    static void Main()
    {
        /* ?????????????? */
        N = int.Parse(Console.ReadLine());
        cities = new List<City>();
        for (int i = 0; i < N; i++)
        {
            int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            cities.Add(new City(i, input[0], input[1]));
        }
        es = new List<Edge>();

        /* ??x????????????????? */
        cities.Sort((a, b) => a.x - b.x);
        for (int i = 0; i < N - 1; i++)
        {
            int s = cities[i].id;
            int g = cities[i + 1].id;
            long l = Math.Abs(cities[i].x - cities[i + 1].x);
            es.Add(new Edge(s, g, l));
        }

        /* ??y????????????????? */
        cities.Sort((a, b) => a.y - b.y);
        for (int i = 0; i < N - 1; i++)
        {
            int s = cities[i].id;
            int g = cities[i + 1].id;
            long l = Math.Abs(cities[i].y - cities[i + 1].y);
            es.Add(new Edge(s, g, l));
        }

        /* ????????????? */
        Console.WriteLine(Kruskal());
    }

    /* ???es??????????????????????????? */
    static long Kruskal()
    {
        es.Sort((a, b) => (a.cost > b.cost) ? 1 : (a.cost == b.cost) ? 0 : -1);

        UF uf = new UF(N);
        long min_cost = 0;

        foreach (var e in es)
        {
            if (!uf.Same(e.a, e.b))
            {
                min_cost += e.cost;
                uf.Unite(e.a, e.b);
            }
        }

        return min_cost;
    }
}

namespace UnionFind
{
    class UF
    {
        private int[] ?; //?[i] : i?????

        public UF(int N) //???????????????????
        {
            ? = new int[N];
            for (int i = 0; i < N; i++)
                ?[i] = i;
        }

        public int Root(int x) //x??????????
        {
            if (?[x] == x) return x;
            return ?[x] = Root(?[x]);
        }

        public void Unite(int x, int y) //x?y?????
        {
            int rx = Root(x);
            int ry = Root(y);
            if (rx == ry) return;
            ?[rx] = ry;
        }

        public bool Same(int x, int y) //x?y???????????????
        {
            return Root(x) == Root(y);
        }
    }
}