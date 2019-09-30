using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input1 = Console.ReadLine().Split(' ');
        int A = int.Parse(input1[0]);
        int B = int.Parse(input1[1]);
        int K = int.Parse(input1[2]);

        int v = 0;
        int c = 0;
        for(int i = A; i >= 0; i--)
        {
            if(A % i == 0 && B % i == 0)
            {
                c++;
                if(c == K)
                {
                    v = i;
                    break;
                }
            }
        }
        Console.WriteLine(v);
    }
}