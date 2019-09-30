using System;

    class Program {
    static void Main(string[] args) {

        string A = Console.ReadLine();
        string B = Console.ReadLine();

        Console.Write(A.Length > B.Length ? A : B);
    }
    }