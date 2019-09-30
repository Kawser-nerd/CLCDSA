using System;
using System.Collections.Generic;

namespace ABC_A_WhiteCells
{
    class Program
    {
        static void Main(string[] args)
        {
            IReadOnlyList<string> stdin = GetStandardInput();

            if (stdin == null)
                return;

            IReadOnlyList<int> vsi = ValidateStandardInput(stdin);

            if (vsi == null)
                return;

            var H = vsi[0];
            var W = vsi[1];
            var h = vsi[2];
            var w = vsi[3];

            var ans = (H - h) * (W - w);
            Console.WriteLine(ans.ToString());
        }

        private static List<string> GetStandardInput()
        {
            var strs = new List<string>();

            for (var i = 0; i <= 1; i++)
            {
                var stdin = Console.ReadLine();

                if (!stdin.Contains(" "))
                {
                    Console.WriteLine("Too few arguments.");
                    return null;
                }

                var arr = stdin.Split(' ');

                if (arr.Length >= 3)
                {
                    Console.WriteLine("Too many arguments.");
                    return null;
                }

                strs.Add(arr[0]);
                strs.Add(arr[1]);
            }

            return strs;
        }

        private static List<int> ValidateStandardInput(IReadOnlyList<string> input)
        {
            var errorMessage = string.Empty;
            int o = int.MinValue;

            if (!int.TryParse(input[0], out o))
                errorMessage += "H is not a number.\r\n";
            if (!int.TryParse(input[1], out o))
                errorMessage += "W is not a number.\r\n";
            if (!int.TryParse(input[2], out o))
                errorMessage += "h is not a number.\r\n";
            if (!int.TryParse(input[3], out o))
                errorMessage += "w is not a number.\r\n";

            if (errorMessage != string.Empty)
            {
                Console.Write(errorMessage);
                return null;
            }

            errorMessage = string.Empty;

            var ints = new List<int>()
            {
                int.Parse(input[0]),
                int.Parse(input[1]),
                int.Parse(input[2]),
                int.Parse(input[3])
            };

            if (ints[0] < 1 || ints[0] > 20)
                errorMessage += "Out of range at H\r\n";
            if (ints[1] < 1 || ints[1] > 20)
                errorMessage += "Out of range at W\r\n";
            if (ints[2] < 1 || ints[2] > ints[0] || ints[2] > 20)
                errorMessage += "Out of range at h\r\n";
            if (ints[3] < 1 || ints[3] > ints[1] || ints[3] > 20)
                errorMessage += "Out of range at w\r\n";

            if (errorMessage != string.Empty)
            {
                Console.Write(errorMessage);
                return null;
            }

            return ints;
        }
    }
}