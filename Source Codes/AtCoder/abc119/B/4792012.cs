using System;
     
    class Problem
    {
        static void Main()
        {
            int N = int.Parse(Console.ReadLine());
            decimal m;
            string u;
            decimal money=0;
            for (int i=0; i<N; i++)
            {
                string[] a = Console.ReadLine().Split(' ');
                m = decimal.Parse(a[0]);
                if (a[1] == "BTC")
                {
                    money += 380000 * m;
                }
                else
                {
                    money += m;
                }
            }
            Console.WriteLine(money);
        }
    }