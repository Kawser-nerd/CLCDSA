using System;

    class Program {
        static void Main(string[] args) {
       int Month = int.Parse(Console.ReadLine());
        if (Month == 12) {
            Console.WriteLine(1);
        }
        else {
            Console.WriteLine(Month + 1);
        }
        }
    }