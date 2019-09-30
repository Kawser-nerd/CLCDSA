using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var result = str == "a" || str == "i" || str == "u" || str == "e" || str == "o"?"vowel":"consonant";
        Console.WriteLine(result);
    }
}