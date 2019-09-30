using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static T Get<T>(object obj)
        {
            return (T)Convert.ChangeType(obj, typeof(T));
        }

        static string[] map  = new string[]{ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

        static bool subtract(Dictionary<char, int> input, string find)
        {
            foreach (var c in find)
            {
                if (!input.ContainsKey(c))
                    return false;
                --input[c];
                if (input[c] < 0)
                    return false;
            }
            return true;
        }

        static string solve(Dictionary<char, int> input, int val)
        {
            if (val > 9)
                return null;
            var app = "";
            while(subtract(input, map[val]))
            {
                app += val.ToString();
                if (input.All(x => x.Value == 0))
                {
                    return app;
                }
                for (var z = val + 1; z < 5; ++z)
                {
                    var temp = solve(new Dictionary<char, int>(input), rel[z]);
                    if (temp != null)
                        return app + temp;
                }                
            }
            return null;
        }

        static int[] rel = new int[] { 1, 3, 5, 7, 9 };

        static void Main(string[] args)
        {
#if !DEBUG
            Console.SetIn(new StreamReader("input.txt"));
            Console.SetOut(new StreamWriter("output.txt"));      
#endif
            int t = Get<int>(Console.ReadLine());
            for (var i = 1; i <= t; ++i)
            {
                var s = Console.ReadLine();
                var answer = "";
                var answer2 = "";
                var cont = new Dictionary<char, int>();
                foreach (var z in s)
                {
                    if (cont.ContainsKey(z))
                        cont[z]++;
                    else
                        cont[z] = 1;
                }
                while (cont.ContainsKey('Z') && cont['Z'] > 0)
                {
                    subtract(cont, "ZERO");
                    answer += "0";
                }
                while (cont.ContainsKey('X') && cont['X'] > 0)
                {
                    subtract(cont, "SIX");
                    answer += "6";
                }
                while (cont.ContainsKey('G') && cont['G'] > 0)
                {
                    subtract(cont, "EIGHT");
                    answer += "8";
                }
                while (cont.ContainsKey('W') && cont['W'] > 0)
                {
                    subtract(cont, "TWO");
                    answer += "2";
                }
                while (cont.ContainsKey('U') && cont['U'] > 0)
                {
                    subtract(cont, "FOUR");
                    answer += "4";
                }
                while (cont.ContainsKey('R') && cont['R'] > 0)
                {
                    subtract(cont, "THREE");
                    answer += "3";
                }
                while (cont.ContainsKey('F') && cont['F'] > 0)
                {
                    subtract(cont, "FIVE");
                    answer += "5";
                }
                while (cont.ContainsKey('O') && cont['O'] > 0)
                {
                    subtract(cont, "ONE");
                    answer += "1";
                }
                while (cont.ContainsKey('I') && cont['I'] > 0)
                {
                    subtract(cont, "NINE");
                    answer += "9";
                }
                while (cont.ContainsKey('S') && cont['S'] > 0)
                {
                    subtract(cont, "SEVEN");
                    answer += "7";
                }
                //for (int j = 0;j < 5; ++j)
                //{
                //    answer2 = solve(new Dictionary<char, int>(cont), rel[j]);
                //    if (answer2 != null)
                //        break;
                //}
                //answer += answer2;
                Console.WriteLine("Case #{0}: {1}", i, new string(answer.OrderBy(c => c).ToArray()));
            }
            Console.Out.Flush();
        }
    }
}