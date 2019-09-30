using System;

    class Program {
    static void Main(string[] args) {

        string A = Console.ReadLine();
        string B = Console.ReadLine();

        if(A.Length > B.Length) {
            Console.WriteLine(A);
        }
        else {
            Console.WriteLine(B);
        }
    }
    }