using System;

namespace AtCoder.ABC093
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            string s1 = input[0];

            int a = 0;
            int b = 0;
            int c = 0;
            for (int i = 0; i < s1.Length; i++)
            {
                if (s1[i].ToString() == "a")
                {
                    a++;
                }
                if (s1[i].ToString() == "b")
                {
                    b++;
                }
                if (s1[i].ToString() == "c")
                {
                    c++;
                }
            }
        
            Console.WriteLine(a == 1 && b ==1 && c == 1 ? "Yes": "No");
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC093.A.Solve();
        }
    }
}