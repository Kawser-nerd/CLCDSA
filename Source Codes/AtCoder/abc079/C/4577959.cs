using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var strABCD = input.Select(c=>c.ToString()).ToList();

            var opList = new List<List<string>>()
            {
                new List<string>(){ "+", "+", "+" },
                new List<string>(){ "+", "+", "-" },
                new List<string>(){ "+", "-", "+" },
                new List<string>(){ "+", "-", "-" },
                new List<string>(){ "-", "+", "+" },
                new List<string>(){ "-", "+", "-" },
                new List<string>(){ "-", "-", "+" },
                new List<string>(){ "-", "-", "-" },
            };

            Func<string, int> Calc = (str) =>
             {
                 var ans = int.Parse(str[0].ToString());
                 for(int i = 2;i<str.Length;i++)
                 {
                     if (str[i-1] == '-'|| str[i - 1] == '+')
                     {
                         ans += int.Parse(str[i - 1].ToString() + str[i].ToString());
                     }
                 }
                 return ans;
             };

            foreach (var item in opList)
            {
                var tmpAnswer = strABCD[0] + item[0] + strABCD[1] + item[1] + strABCD[2] + item[2] + strABCD[3];
                var result = Calc(tmpAnswer);
                if (int.Parse(result.ToString()) != 7) continue;
                Console.WriteLine(tmpAnswer + "=7");
                return;
            }

        }
    }