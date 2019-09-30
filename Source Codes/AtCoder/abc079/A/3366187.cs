using System;

class Atcoder67
{
    public static void Main()
    {
        string number = Console.ReadLine();
        char thou = number[0];
        char hund = number[1];
        char ten = number[2];
        char one = number[3];

        if (thou == hund && thou == ten)
            Console.WriteLine("Yes");
        else if (hund == ten && hund == one)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}