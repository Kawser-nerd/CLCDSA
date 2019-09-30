using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1AC
{
    class Program
    {
        static void Main(string[] args)
        {
            //FileStream stream = new FileStream(@"C:\Users\taniguchi\Documents\Downloads\A-large.in", FileMode.Open);
            //StreamReader reader = new StreamReader(stream);

            TextReader reader = Console.In;

            int T = int.Parse(reader.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string line = reader.ReadLine();
                int A1 = int.Parse(line.Split()[0]);
                int A2 = int.Parse(line.Split()[1]);
                int B1 = int.Parse(line.Split()[2]);
                int B2 = int.Parse(line.Split()[3]);

                int count = 0;
                for (int a = A1; a <= A2; a++)
                    for (int b = B1; b <= B2; b++)
                        if (isWinner(a, b))
                            count++;

                Console.WriteLine("Case #{0}: {1}", t + 1, count);
            }
        }

        static int N = 5000;
        static int[,] ans = new int[N, N];

        static bool isWinner(int a, int b)
        {
            if (a < N && b < N)
            {
                if (ans[a, b] != 0)
                    return ans[a, b] == 1;
            }

            if (a == b)
                return false;

            if (a > b)
                return isWinner(b, a);

            //a < b

            for (int k = (b - 1) / a; k > 0; k--)
                if (!isWinner(a, b - k * a))
                {
                    if (a < N && b < N)
                    {
                        ans[a, b] = 1;
                    }
                    
                    return true;
                }

            if (a < N && b < N)
            {
                ans[a, b] = 0;
            }
            return false;
        }
    }
}
