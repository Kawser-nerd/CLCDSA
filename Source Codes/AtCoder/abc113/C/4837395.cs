using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static int M;

    class Comare : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            return x - y;
        }
    }

    class CityInfo
    {
        public CityInfo(int k, int y, int c)
        {
            Ken = k;
            Year = y;
            CityNo = c;
        }

        public int Ken;
        public int Year;
        public int CityNo;
    }

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();

        var Cities = new List<CityInfo>();
        var Kens = new Dictionary<int, List<CityInfo>>();
        for (int i = 0; i < M; i++)
        {
            var l = Input.LineInt();
            var ken_no = l[0];
            var city_born = l[1];

            if (!Kens.ContainsKey(ken_no))
                Kens[ken_no] = new List<CityInfo>();
            var city = new CityInfo(ken_no, city_born, 0);
            Cities.Add(city);
            Kens[ken_no].Add(city);
        }
        foreach (var en in Kens)
        {
            en.Value.Sort((a, b) => (a.Year - b.Year));
            for (int i = 0; i < en.Value.Count; i++)
            {
                en.Value[i].CityNo = i + 1;
            }
        }

        foreach (var city in Cities)
        {
            Console.WriteLine($"{Make6(city.Ken)}{Make6(city.CityNo)}");
        }
    }

    static string Make6(int x)
    {
        string s;
        s = "000000" + x.ToString();
        return s.Substring(s.Length - 6);
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}