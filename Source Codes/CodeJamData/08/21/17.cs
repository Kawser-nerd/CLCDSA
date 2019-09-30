using System.IO;

public class Program
{
    public static void Main()
    {
        using (var reader = new StreamReader("input.txt"))
        using (var writer = new StreamWriter("output.txt"))
        {
            var N = int.Parse(reader.ReadLine());
            for (var i = 0; i < N; i++)
            {
                var s = reader.ReadLine().Split();
                var n = int.Parse(s[0]);
                var A = int.Parse(s[1]);
                var B = int.Parse(s[2]);
                var C = int.Parse(s[3]);
                var D = int.Parse(s[4]);
                var x0 = int.Parse(s[5]);
                var y0 = int.Parse(s[6]);
                var M = int.Parse(s[7]);
                int[] x = new int[n], y = new int[n];
                x[0] = x0;
                y[0] = y0;
                for (var j = 1; j < n; j++)
                {
                    x[j] = (int) (((long) A * x[j - 1] + B) % M);
                    y[j] = (int) (((long) C * y[j - 1] + D) % M);
                }
                var res = f(x, y);
                writer.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }

    static long f(int[] x, int[] y)
    {
        var n = x.Length;
        var v = new int[9];
        for (var i = 0; i < n; i++)
        {
            var t1 = x[i] % 3;
            var t2 = y[i] % 3;
            v[3 * t1 + t2]++;
        }
        long res = 0;
        for (var i = 0; i < v.Length; i++)
        {
            for (var j = i; j < v.Length; j++)
            {
                for (var k = j; k < v.Length; k++)
                {
                    if ((i + j + k) % 3 == 0 && (i / 3 + j / 3 + k / 3) % 3 == 0)
                    {
                        if (i == j && j == k) res += (long) v[i] * (v[j] - 1) * (v[k] - 2) / 6;
                        else if (i == j) res += (long)v[i] * (v[j] - 1) * v[k] / 2;
                        else if (j == k) res += (long)v[i] * v[j] * (v[k] - 1) / 2;
                        else res += (long)v[i] * v[j] * v[k];
                    }
                }
            }
        }
        return res;
    }
}