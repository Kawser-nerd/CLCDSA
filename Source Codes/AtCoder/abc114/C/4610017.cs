using System;

namespace _755
{
    class Program
    {
        static double N;
        static void Main(string[] args)
        {
            N = double.Parse(Console.ReadLine());
            Console.WriteLine(Dfs("0"));
        }

        public static int Dfs(string s)
        {
            if (double.Parse(s) > N) { return 0; }

            int result = 0;
            if (s.Contains("7") && s.Contains("5") && s.Contains("3")) { result++; }

            foreach (var item in "753")
            {
                result += Dfs(s + item);
            }
            return result;
        }
    }
}