using System.Collections.Generic;
using System.IO;
using System.Linq;

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
                var A = long.Parse(s[0]);
                var B = long.Parse(s[1]);
                var P = long.Parse(s[2]);
                var res = f(A, B, P);
                writer.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }

    static long f(long a, long b, long p)
    {
        var dic = new Dictionary<long, long>();
        var numbers = new HashSet<long>[b - a + 1];
        var primes = new HashSet<long>[b - a + 1];
        for (long v = a; v <= b; v++)
        {
            var nums = new HashSet<long> {v};
            var ps = new HashSet<long>();
            foreach (long l in PrimeFactorization(v))
            {
                if (l >= p)
                {
                    ps.Add(l);
                    if (dic.ContainsKey(l))
                    {
                        foreach (var l1 in primes[dic[l] - a])
                        {
                            ps.Add(l1);
                        }
                        foreach (var l1 in numbers[dic[l] - a])
                        {
                            nums.Add(l1);
                        }
                    }
                }
            }
            foreach (long l in ps)
            {
                dic[l] = v;
            }
            foreach (var num in nums)
            {
                numbers[num - a] = null;
                primes[num - a] = null;
            }
            numbers[v - a] = nums;
            primes[v - a] = ps;
        }
        return numbers.Count(set => set != null);
    }

    public static IEnumerable<long> PrimeFactorization(long value)
    {
        long k = 2;
        while (value != 1)
        {
            while (value % k != 0) k++;
            while (value % k == 0)
            {
                yield return k;
                value /= k;
            }
        }
    }
}