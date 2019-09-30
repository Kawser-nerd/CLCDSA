using System;
class Program
{
    public static void Main()
    {

        string[] str = Console.ReadLine().Split(' ');
        Array.Sort(str);
        if (str[0] != str[1])
            Console.WriteLine(str[0]);
        else if (str[1] != str[2])
            Console.WriteLine(str[2]);
        else
            Console.WriteLine(str[1]);
    }
}