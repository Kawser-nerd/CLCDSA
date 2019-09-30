using System;

class Atcoder61
{
    public static void Main()
    {
        string input = Console.ReadLine();
        char ten = input[0];
        char one = input[1];

        string strten = ten.ToString();
        string strone = one.ToString();

        if (strten == "9" || strone == "9")
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}