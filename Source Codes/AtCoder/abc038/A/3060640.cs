using System;

class Atcoder32
{
    public static void Main()
    {
        string lastletter = "T";

        string drink = Console.ReadLine();
        int length = drink.Length;
        char letter = drink[length - 1];
        string strletter = letter.ToString();

        if (strletter == lastletter)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
         
    }
}