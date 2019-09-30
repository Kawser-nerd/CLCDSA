using System;
using static System.Console;
using System.Linq;
using System.Collections.Generic;

static class Program
{
    static void Main()
    {
        int[] input = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        Tyoten[] tyotens = new Tyoten[input[0]];
        for (int i = 0; i < tyotens.Length; i++)
        {
            tyotens[i] = new Tyoten((i + 1).ToString());
        }

        for (int i = 0; i < input[1]; i++)
        {
            int[] hen = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Tyoten.Connect(tyotens[hen[0] - 1], tyotens[hen[1] - 1]);
        }

        int count = 0;

        List<Route> routes = new List<Route>();
        routes.Add(new Route(tyotens[0]));
        while (routes.Count > 0)
        {
            if (routes[0].UsedTyotens.Count == tyotens.Length)
            {
                ++count;
                routes.RemoveAt(0);
            }
            else
            {
                IEnumerable<Route> route = routes[0].GetNextRoutes();
                if (route.Count() == 0)
                {
                    routes.RemoveAt(0);
                }
                else
                {
                    routes.RemoveAt(0);
                    routes.AddRange(route);
                }
            }
        }

        WriteLine(count);
        ReadKey();
    }
}

public class Tyoten
{
    public string Name { get; set; }
    public List<Tyoten> ConnentedTyoten { get; private set; }

    public Tyoten()
    {
        ConnentedTyoten = new List<Tyoten>();
    }

    public Tyoten(string name)
    {
        ConnentedTyoten = new List<Tyoten>();
        Name = name;
    }

    public static void Connect(Tyoten a, Tyoten b)
    {
        a.ConnentedTyoten.Add(b);
        b.ConnentedTyoten.Add(a);
    }
}

public class Route
{
    public List<Tyoten> UsedTyotens { get; private set; }
    public Tyoten NowPoint { get; set; }

    public Route(Tyoten NowPoint)
    {
        UsedTyotens = new List<Tyoten>();
        UsedTyotens.Add(NowPoint);
        this.NowPoint = NowPoint;
    }

    public Route(Route route, Tyoten NextPoint)
    {
        UsedTyotens = new List<Tyoten>(route.UsedTyotens);
        NowPoint = NextPoint;
        UsedTyotens.Add(NextPoint);
    }

    public IEnumerable<Route> GetNextRoutes()
    {
        foreach (Tyoten tyoten in NowPoint.ConnentedTyoten)
        {
            if (!UsedTyotens.Contains(tyoten))
            {
                yield return new Route(this, tyoten);
            }
        }
    }
}