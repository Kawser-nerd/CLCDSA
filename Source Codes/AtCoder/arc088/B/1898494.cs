using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        string input = Console.ReadLine();
        List<int> list = new List<int>();
        list.Add(1);
        char chainc = input[0];
        input = input.Substring(1);
        foreach (var c in input)
        {
            if (c == chainc)
            {
                list[list.Count - 1]++;
            }
            else
            {
                list.Add(1);
                chainc = c;
            }
        }
        int sum = 0;
        double border = (double)(input.Length + 1) / 2;
        foreach (var i in list)
        {
            if (sum <= border && sum + i >= border)
            {
                int result = Math.Min(input.Length + 1 - sum, sum + i);
                Console.WriteLine(result);
                break;
            }
            sum += i;
        }
    }
}