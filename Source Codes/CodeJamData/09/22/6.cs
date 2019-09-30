using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemB
{
    class Program
    {
        static string Solve(string number)
        {
            for (int i = 2; i <= number.Length; i++)
            {
                int index = -1;
                for (int j = 1; j < i; j++)
                {
                    char first = number[number.Length - i];
                    char curr = number[number.Length - j];
                    if (curr > first)
                    {
                        if (index == -1 || curr < number[index])
                        {
                            index = number.Length - j;
                        }
                    }
                }
                if (index != -1)
                {
                    string answer = number.Substring(0, number.Length - i) + number[index];
                    char[] digits = number.Substring(number.Length - i).Remove(
                        index - number.Length + i, 1).ToCharArray();
                    Array.Sort(digits);
                    answer += new String(digits);
                    return answer;
                }
            }
            {
                int index = -1;
                for (int j = 0; j < number.Length; j++)
                {
                    if (index == -1 || (number[j] > '0' && number[j] < number[index]))
                    {
                        index = j;
                    }
                }

                string answer = "" + number[index];
                char[] digits = (number.Remove(index, 1) + "0").ToCharArray();
                Array.Sort(digits);
                answer += new String(digits);
                return answer;
            }
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < T; i++)
                    {
                        string answer = Solve(reader.ReadLine().Trim());
                        writer.WriteLine("Case #" + (i + 1) + ": " + answer);
                    }
                }
            }
        }
    }
}
