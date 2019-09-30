using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CandiSplitting
{
    class Program
    {
        String[] input;
        int p = 0;

        double GetDouble()
        {
            return double.Parse(GetString());
        }

        int GetInt()
        {
            return int.Parse(GetString());
        }

        string GetString()
        {
            return input[p++];
        }


        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            using (StreamReader sr = new StreamReader("..\\..\\C-large.in"))
            {
                input = sr.ReadToEnd().Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
            }

            using (StreamWriter sw = new StreamWriter("..\\..\\out.txt"))
            {

                int T = GetInt();

                for (int t = 1; t <= T; t++)
                {
                    int C = GetInt();
                    List<int> candy = new List<int>(C);
                    while (C-- > 0)
                    {
                        int c = GetInt();
                        candy.Add(c);
                    }
                    string ans = Solve(candy);
                    sw.WriteLine("Case #{0}: {1}", t, ans);
                }
            }
        }

        private string Solve(List<int> candy)
        {
            int s1 = candy.Aggregate((a, b) => a ^ b);
            if (s1 != 0) return "NO";
            int sum = candy.Aggregate((a, b) => a + b);
            return (sum - candy.Min()).ToString();
        }
    }
}
