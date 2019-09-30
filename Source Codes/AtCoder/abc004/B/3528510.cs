using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ???4?4??????????string?????
            string[] line = new string[4];

            // ??????1?????
            for(int i = 0; i < line.Length; i++)
            {
                line[i] = Console.ReadLine();
            }

            // 180???????????????
            for(int i = line.Length-1; i>=0; i--)
            {
                for(int j = 6; j>=0; j--)
                {
                    Console.Write(line[i][j]);
                }
                Console.WriteLine();
            }
        }
    }
}