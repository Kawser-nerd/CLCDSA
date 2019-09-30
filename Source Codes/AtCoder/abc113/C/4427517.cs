using System;

class City
{
    public int i, p, y, b;

    public City(int i, int p, int y)
    {
        this.i = i;
        this.p = p;
        this.y = y;
    }
}

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = int.Parse(nm[0]);
        var m = int.Parse(nm[1]);

        var cities = new City[m];
        for (int i = 0; i < m; i++)
        {
            var py = Console.ReadLine().Split(' ');
            cities[i] = new City(i, int.Parse(py[0]), int.Parse(py[1]));
        }

        Array.Sort(cities, (a, b) => a.p == b.p ? a.y - b.y : a.p - b.p);

        cities[0].b = 1;
        for (int i = 1; i < m; i++)
        {
            if (cities[i - 1].p == cities[i].p)
            {
                cities[i].b = cities[i - 1].b + 1;
            }
            else
            {
                cities[i].b = 1;
            }
        }

        Array.Sort(cities, (a, b) => a.i - b.i);

        for (int i = 0; i < m; i++)
        {
            Console.WriteLine("{0:D6}{1:D6}", cities[i].p, cities[i].b);
        }
    }
}