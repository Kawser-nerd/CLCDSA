using System;
using System.Linq;

namespace ABC002
{
    public class ABC002_B
    {
        static void Main(string[] args)
        {
            string inputWord = Console.ReadLine();
            string trimCharacters = "aiueo";

            foreach (var character in inputWord)
            {
                if (trimCharacters.Contains(character))
                {
                    continue;
                }
                Console.Write(character);
            }
            Console.WriteLine();
        }
    }
}