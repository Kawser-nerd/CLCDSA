using System;
using System.Linq;
public class Aprob {
    public static void Main() {
        int n = int.Parse(Console.ReadLine());
        string[] readSome = new string[n];
        readSome = Console.ReadLine().Split(' ');
        int[] N = new int[n];
        int every = 0;
        for (int i = 0; i < n; i++) {
            N[i] = int.Parse(readSome[i]);
            every += N[i];
        }
        int outp = 0;
        if (every % n != 0) {
            outp = -1;
        } else {
            int member = every / n;
            for (int i = 0; i < n-1; i++) {
                if (N[i] != member) {
                    outp++;
                    N[i + 1] += N[i] - member;
                }
            }
        }
        Console.WriteLine(outp);
    }
}