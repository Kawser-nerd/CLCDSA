using System;

class Atcoder22
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int A = int.Parse(input[0]);
        int B = int.Parse(input[1]);
        int C = int.Parse(input[2]);
        int K = int.Parse(input[3]);
        string[] inputa = Console.ReadLine().Split(' ');
        int S = int.Parse(inputa[0]);
        int T = int.Parse(inputa[1]);

        int ST = S + T;

        if(ST >= K) {
            int money = A * S + B * T - C * ST;
            Console.WriteLine(money);
        }
        else {
            int money = A * S + B * T;
            Console.WriteLine(money);
        }
    }
}