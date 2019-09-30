using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');

        int x = int.Parse(input[0]+input[1]);

        for(int i=1;i<=x;i++)
        {
            if((i*i)==x)
            {
                Console.WriteLine("Yes");
                return;
            }
        }
        Console.Write("No");
    }
}