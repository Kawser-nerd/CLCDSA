using System;
using System.Linq;
public class Test
{
    public static void Main()
    {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = new int[n[0]+1];
        for (int i = 0; i < a.Length; i++) { a[i] = i; }
        for (int i = 0; i < n[1]; i++)
        {
            int s = int.Parse(Console.ReadLine());
            int Toru = 0;
            for (int ij = 0; ij < a.Length; ij++) {if (a[ij] == s) { Toru = ij; break; } }
            int r = a[Toru];
            a[Toru] = a[0];
            a[0] = r;
        }
        for (int i = 1; i < a.Length; i++)
        {
            Console.WriteLine(a[i]);
        }Console.ReadLine();
    }
}