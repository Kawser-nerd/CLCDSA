using System;

class Program {
    static void Main(string[] args) {
        string input = Console.ReadLine();
        int a = int.Parse(input.Substring(0, 1));
        int b = int.Parse(input.Substring(1, 1));
        int c = int.Parse(input.Substring(2, 1));
        int result = 0;
        if (a == 1) {
            result++;
        }
        if (b == 1) {
            result++;
        }
        if (c == 1) {
            result++;
        }
        Console.WriteLine(result);

    }
}