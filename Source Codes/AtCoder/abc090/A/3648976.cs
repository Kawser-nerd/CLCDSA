using System;

namespace ABC090
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] hoge = new string[3];
           for(int i = 0; i < 3; i++)
            {
                hoge[i] = Read();
            }

            Console.WriteLine(hoge[0][0].ToString() + hoge[1][1].ToString() + hoge[2][2].ToString());
        }

        public static string Read() { return Console.ReadLine(); }
    }
}