using System;

namespace arc008_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            string a = Console.ReadLine();
            int[] name = new int[26];
            for (int i = 0; i < a.Length; i++)
            {
                name[a[i] - 65]++;
            }
            string b = Console.ReadLine();
            int[] kit = new int[26];
            for (int i = 0; i < b.Length; i++)
            {
                kit[b[i] - 65]++;
            }
            int max = 0;
            bool canmake = true;
            for (int i = 0; i < 26; i++)
            {
                if (name[i] > 0)
                {
                    if (kit[i] == 0)
                    {
                        canmake = false;
                    }
                    else
                    {
                        max = Math.Max(max, (name[i] + kit[i] - 1) / kit[i]);
                    }
                }
            }
            Console.WriteLine(canmake ? max : -1);
        }
    }
}