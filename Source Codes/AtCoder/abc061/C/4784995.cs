using System;

class Program
{
    static void Main(string[] args)
    {
        var nm = Console.ReadLine().Split(' ');
        var n = long.Parse(nm[0]);
        var m = long.Parse(nm[1]);

        var d = new Tuple<int, int>[n];
        for (int i = 0; i < n; i++)
        {
            var ab = Console.ReadLine().Split(' ');
            d[i] = Tuple.Create(int.Parse(ab[0]), int.Parse(ab[1]));
        }

        Array.Sort(d, (x, y) => x.Item1 - y.Item1);

        var sum = 0L;
        for (int i = 0; i < n; i++)
        {
            sum += d[i].Item2;
            if (m <= sum)
            {
                Console.WriteLine(d[i].Item1);
                return;
            }
        }
    }
}