using System;
using System.Linq;

namespace arc093_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0]--; x[1]--;
            Console.WriteLine(100 + " " + 100);
            int count = 0;
            for (int i = 0; 50 <= x[0]; i++)
            {
                for (int j = 0; j < 100; j++) Console.Write('#');
                Console.WriteLine(); count++;
                for (int j = 0; j < 100; j++) Console.Write(j % 2 == 0 ? '.' : '#');
                Console.WriteLine(); count++;
                x[0] -= 50;
            }
            for (int j = 0; j < 100; j++) Console.Write('#');
            Console.WriteLine(); count++;
            for (int j = 0; j < 50; j++)
            {
                if (j < x[0]) Console.Write(".#");
                else Console.Write("##");
            }
            Console.WriteLine(); count++;
            for (int j = 0; j < 100; j++) Console.Write('#');
            Console.WriteLine(); count++;

            for (int i = 0; 50 <= x[1]; i++)
            {
                for (int j = 0; j < 100; j++) Console.Write('.');
                Console.WriteLine(); count++;
                for (int j = 0; j < 100; j++) Console.Write(j % 2 == 0 ? '.' : '#');
                Console.WriteLine(); count++;
                x[1] -= 50;
            }
            for (int j = 0; j < 100; j++) Console.Write('.');
            Console.WriteLine(); count++;
            for (int j = 0; j < 50; j++)
            {
                if (j < x[1]) Console.Write("#.");
                else Console.Write("..");
            }
            Console.WriteLine(); count++;
            for (; count < 100; count++)
            {
                for (int j = 0; j < 100; j++) Console.Write('.');
                Console.WriteLine();
            }
        }
    }
}