using System;

    class Program {
    static void Main(string[] args) {

        string[] str = Console.ReadLine().Split(' ');

        Console.WriteLine(int.Parse(str[0]) % int.Parse(str[1]) == 0 ? "YES" : "NO");
    }
    }