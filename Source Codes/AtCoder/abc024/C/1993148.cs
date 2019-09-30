using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var d = int.Parse(line[1]);
        var k = int.Parse(line[2]);
        var L = new int[d];
        var r = new int[d];
        for (int i = 0; i < d; i++)
        {
            string[] line2 = Console.ReadLine().Trim().Split(' ');
            L[i] = int.Parse(line2[0]);
            r[i] = int.Parse(line2[1]);
        }
        for (int i = 0; i < k; i++)
        {
            string[] line3 = Console.ReadLine().Trim().Split(' ');
            var s = int.Parse(line3[0]);
            var t = int.Parse(line3[1]);
            Console.WriteLine(getFirstDay(L, r, s, t));
        }
    }
    public static int getFirstDay(int[] L, int[] r, int s, int t)
    {
        var gomin = s; var gomax = s;
        for (int i = 0; i < L.Length; i++)
        {
            if (L[i] < gomin && gomin <= r[i]) gomin = L[i];
            if (r[i] > gomax && gomax >= L[i]) gomax = r[i];
            if (t >= gomin && t <= gomax) return i + 1;
        }
        return 0;
    }
}