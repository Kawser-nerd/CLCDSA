using System;

namespace AtCoder.ABC090
{
    public class A
    {
        public static void Solve()
        {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            string s3 = Console.ReadLine();

            Console.WriteLine(s1[0].ToString()+s2[1].ToString()+s3[2].ToString());
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC090.A.Solve();
        }
    }
}