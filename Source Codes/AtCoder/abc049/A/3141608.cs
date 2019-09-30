using System;

class Atcoder41
{
    public static void Main()
    {
        string letter = Console.ReadLine();

        if (letter == "a" || letter == "e" || letter == "i" || letter == "o" || letter == "u")
            Console.WriteLine("vowel");
        else
            Console.WriteLine("consonant");
    }
}