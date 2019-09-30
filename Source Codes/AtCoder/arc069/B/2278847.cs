using System;

namespace arc069_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            bool[] sheep = new bool[n + 2];
            bool[,] hoge = new bool[,]
            {
                {true,true },
                {true,false },
                {false,true },
                {false,false },
            };
            bool flag = true;
            for (int i = 0; i < 4; i++)
            {
                sheep[0] = hoge[i,0]; sheep[1] = hoge[i,1];
                for (int j = 2; j < n + 2; j++)
                {
                    sheep[j] = (s[(j - 1) % n] == 'o') == sheep[j - 1] ? sheep[j - 2] : !sheep[j - 2];
                }
                if (sheep[0] == sheep[n] && sheep[1] == sheep[n + 1])
                {
                    flag = false;
                    break;
                }
            }
            if (flag) Console.WriteLine(-1);
            else
            {
                for (int i = 0; i < n; i++) Console.Write(sheep[i] ? "S" : "W");
            }
        }
    }
}