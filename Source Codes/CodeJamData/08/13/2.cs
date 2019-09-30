using System;
using System.Collections.Generic;
using System.IO;

using System.Text;

public class Test
{
    public static void Main(string[] args)
    {
        using (StreamReader sr = new StreamReader("C:\\Users\\int\\Desktop\\test.in"))
        {
            int n = int.Parse(sr.ReadLine());
            using (StreamWriter sw = new StreamWriter("C:\\Users\\int\\Desktop\\test.out"))
            {
                for (int c = 0; c < n; c++)
                {
                    int s = int.Parse(sr.ReadLine());
                    int[] a = new int[s+1];
                    a[1] = 6;
                    a[2] = 28;
                    for (int k = 3; k <= s; k++)
                    {
                        a[k] = 6 * a[k - 1] - 4 * a[k - 2];
                        a[k] = a[k] + 1000;
                        a[k] %= 1000;
                    }
                    int t = a[s] - 1;
                    t = (t + 1000) % 1000;
                    int x = t / 100 % 10;
                    int y = t / 10 % 10;
                    int z = t % 10;
                    sw.WriteLine("Case #{0}: {1}{2}{3}", c + 1, x, y, z);
                }
            }
        }
    }
}
