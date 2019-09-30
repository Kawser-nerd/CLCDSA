using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        //List<int> values = new List<int>(Console.ReadLine().Split(' ').Select(s => int.Parse(s)));
        //List<int> values = new List<int>();

        string input = Console.ReadLine();
        int n = int.Parse(input.Split(' ')[0]);
        int m = int.Parse(input.Split(' ')[1]);
        //int k = int.Parse(input.Split(' ')[2]);

        List<string> ss = new List<string>();

        for (int i = 0; i < n; i++)
        {
            ss.Add(Console.ReadLine());
        }

        ss.Sort();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
        {
            sb.Append(ss[i]);
        }


        
        

        Console.WriteLine(sb.ToString());
        input = Console.ReadLine();

    }
}