using System;

class Program {
    static void Main(string[] args) {
        var s = Console.ReadLine();
        var a = new int[6];
        foreach (var i in s) {
            a[i - 65]++;
        }
        for (int i = 0; i < 5; i++) {
            Console.Write($"{a[i]} ");
        }
        Console.WriteLine(a[5]);
    }
}