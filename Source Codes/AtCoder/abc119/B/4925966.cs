using System;
class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        double sum = 0;
        for(int i = 0; i < N; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            if(input[1][0] == 'J')
            {
                sum += float.Parse(input[0]);
            }
            else
            {
                sum += float.Parse(input[0]) * 380000f;
            }
        }
        Console.WriteLine(sum);
    }
}