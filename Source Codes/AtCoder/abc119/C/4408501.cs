using System;

class Data
{
    public int count, sum, n;

    public Data(int count, int sum, int n)
    {
        this.count = count;
        this.sum = sum;
        this.n = n;
    }
}

class Program
{
    static void Main(string[] args)
    {
        var nabc = Console.ReadLine().Split(' ');
        var n = int.Parse(nabc[0]);
        var a = int.Parse(nabc[1]);
        var b = int.Parse(nabc[2]);
        var c = int.Parse(nabc[3]);

        var d = new int[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(Console.ReadLine());
        }

        var datas = new Data[] {
            new Data(0, 0, 0),
            new Data(0, 0, a),
            new Data(0, 0, b),
            new Data(0, 0, c),
        };

        var ans = m1(d, 0, datas);
        Console.WriteLine(ans);
    }

    static int m1(int[] d, int n, Data[] datas)
    {
        if (d.Length <= n)
        {
            var sum = 0;
            for (int i = 1; i < datas.Length; i++)
            {
                if (datas[i].count == 0)
                {
                    return int.MaxValue;
                }

                sum += (datas[i].count - 1) * 10 + Math.Abs(datas[i].sum - datas[i].n);
            }
            return sum;
        }

        var min = int.MaxValue;
        for (int i = 0; i < datas.Length; i++)
        {
            datas[i].count++;
            datas[i].sum += d[n];
            min = Math.Min(min, m1(d, n + 1, datas));
            datas[i].count--;
            datas[i].sum -= d[n];
        }
        return min;
    }
}