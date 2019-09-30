using System;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int ans = 1;
        if (n > 2)
        {
            int x = 0, y = 0, z = 0;
            for (int i = 0; i < n; i++)
            {
                if (z != a[i])
                {
                    x = y;
                    y = z;
                    z = a[i];
                    if (x > 0 && (x < y && y > z || x > y && y < z))
                    {
                        ans++;
                        x = y = 0;
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }
}