using System;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        int[] x = new int[s.Length-2];
        for (int i = 0; i < s.Length-2; i ++) {
            x[i] = 753 - int.Parse(s.Substring(i, 3));
            if (x[i] < 0) x[i] = x[i] * -1;
        }
        Console.WriteLine(x.Min());
    }
}