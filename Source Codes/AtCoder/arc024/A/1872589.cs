using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        int[] n = Console.ReadLine().Split(' ').Select(m => int.Parse(m)).ToArray();
        int[] a = Console.ReadLine().Split(' ').Select(m => int.Parse(m)).ToArray();
        int[] b = Console.ReadLine().Split(' ').Select(m => int.Parse(m)).ToArray();
        for (int i = 0; i < n[0]; i++) {
            for (int j = 0; j < n[1]; j++) {
                if (a[i] == b[j]) {
                    a[i] = -1;
                    b[j] = -1;
                    break;
                }
            }
        }
        Console.WriteLine(a.Count(c => c == -1));
    }
}