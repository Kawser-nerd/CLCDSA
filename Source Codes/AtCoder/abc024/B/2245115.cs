using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var n = new int[a[0]];
        int count = 0, o = 0;
        for (int i = 0; i < a[0]; i++) {
            n[i] = int.Parse(Console.ReadLine());
            if (i != 0 && n[i] - n[i - 1] > a[1]) count += a[1];
            else if (i != 0) o += n[i] - n[i - 1]; 
        }
        Console.WriteLine(count + o + a[1]);
    }
}