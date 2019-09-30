using System;

public class Class1
{
	static void Main(string[] args)
	{
        int a, b;
        string[] str = Console.ReadLine().Split(' ');

        a = int.Parse(str[0]);
        b = int.Parse(str[1]);

        if (a * b % 2 == 0) {
            Console.WriteLine("Even");
        }
        else{
            Console.WriteLine("Odd");
        }
    }
}