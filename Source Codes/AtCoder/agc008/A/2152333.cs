using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var a = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
        var s = new long[4];
        if (a[1] >= a[0]) s[0] = a[1] - a[0];
        if (-a[1] >= a[0]) s[1] = -a[1] - a[0] + 1;
        if (a[1] >= -a[0]) s[2] = a[1] - (-a[0]) + 1;
        if (-a[1] >= (-a[0])) s[3] = -a[1] - (-a[0]) + 2;
        Array.Sort(s); Console.WriteLine(s[2]);
    }
}