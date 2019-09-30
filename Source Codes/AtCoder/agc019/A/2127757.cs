using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int[] qhsd = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        double n = int.Parse(Console.ReadLine());
        double[][] cost = new double[4][];
        double[] q = { 0.25, 0.5, 1.0, 2.0 };
        int[] m = { 8, 4, 2, 1 };

        for (int i = 0; i < 4; i++)
        {
            cost[i] = new double[3];
            cost[i][0] = q[i];
            cost[i][1] = m[i] * qhsd[i];
            cost[i][2] = qhsd[i];
        }

        Array.Sort(cost, (a, b) => (int)a[1] - (int)b[1]);

        long sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum += (int)Math.Floor(n / cost[i][0]) * (long)cost[i][2];
            n = n % cost[i][0];
        }
        Console.WriteLine(sum);
    }
}