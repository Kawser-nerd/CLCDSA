using System;

class Program
{
    static void Main(string[] args)
    {
        var ks = Console.ReadLine().Split();
        var k = int.Parse(ks[0]);
        var s = int.Parse(ks[1]);

        var ans = 0;
        for (int x = 0; x <= k; x++)
        {
            for (int y = 0; y <= k; y++)
            {
                var z = s - x - y;
                if (0 <= z && z <= k)
                {
                    ans++;
                }
            }
        }

        Console.WriteLine(ans);
    }
}