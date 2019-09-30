using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1??????
            string input = Console.ReadLine();

            // N???
            int n = int.Parse(input);

            // N mod 30????N????
            n = n % 30;

            // ?????????
            int[] card = { 1, 2, 3, 4, 5, 6 };

            // ????????temp?????
            int temp;

            // ???????????
            for(int i = 0; i < n; i++)
            {
                temp = card[i % 5];
                card[i % 5] = card[i % 5 + 1];
                card[i % 5 + 1] = temp;
            }

            // ?????????
            Console.WriteLine(string.Join("",card));
        }
    }
}