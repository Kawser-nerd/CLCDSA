using System;
 
namespace arc071_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] max = new int[26];
            for (int i = 0; i < 26; i++)
            {
                max[i] = int.MaxValue;
            }
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                int[] letter = new int[26];
                for (int j = 0; j < s.Length; j++)
                {
                    letter[s[j] - 97]++;
                }
                for (int j = 0; j < 26; j++)
                {
                    max[j] = Math.Min(max[j], letter[j]);
                }
            }
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < max[i]; j++)
                {
                    Console.Write((char)(i + 97));
                }
            }
            Console.WriteLine();
        }
    }
}