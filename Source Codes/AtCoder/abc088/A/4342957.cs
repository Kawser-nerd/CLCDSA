using System;

namespace AtCoder.ABC088
{
    public class A
    {
        public static void Solve()
        {
            int num = 2;
            var a = new int[num];
            for (int i  = 0; i < num; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }

            bool isPay = false;
            if (a[0] <=a[1])
            {
                isPay = true;
            }
            else
            {
                if (a[0] % 500 <= a[1])
                {
                    isPay = true;
                }
            }    
            
            Console.WriteLine(isPay ? "Yes":"No");
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC088.A.Solve();
        }
    }
}