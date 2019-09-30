using System;

namespace abc039_c
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            if (S == "WBWBWWBWBWBWWBWBWWBW")
            {
                Console.WriteLine("Do");
            }
            else if (S == "WBWWBWBWBWWBWBWWBWBW")
            {
                Console.WriteLine("Re");
            }
            else if (S == "WWBWBWBWWBWBWWBWBWBW")
            {
                Console.WriteLine("Mi");
            }
            else if (S == "WBWBWBWWBWBWWBWBWBWW")
            {
                Console.WriteLine("Fa");
            }
            else if (S == "WBWBWWBWBWWBWBWBWWBW")
            {
                Console.WriteLine("So");
            }
            else if (S == "WBWWBWBWWBWBWBWWBWBW")
            {
                Console.WriteLine("La");
            }
            else
            {
                Console.WriteLine("Si");
            }
            Console.ReadLine();
        }
    }
}