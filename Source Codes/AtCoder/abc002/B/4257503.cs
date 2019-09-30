using System;

class Atcoder107
{
    public static void Main()
    {
        string w = Console.ReadLine();
        int l = w.Length;
        string word = "";

        for (int i = 0; i < l; i++)
        {
            char letter = w[i];

            if (letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u')
            {
                string let = w[i].ToString();
                word += let;
            }
        }

        Console.WriteLine(word);
    }
}