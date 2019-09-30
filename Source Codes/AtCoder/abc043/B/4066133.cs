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
        //int n = int.Parse(input.Split(' ')[0]);
        //int m = int.Parse(input.Split(' ')[1]);
        //int k = int.Parse(input.Split(' ')[2]);

        string ss = "";


        foreach (var item in input)
        {
            if (item.Equals('B'))
            {
                if (ss.Length != 0)
                {
                    ss=ss.Remove(ss.Length - 1, 1);
                }
            }
            else
            {
                ss += item;
            }
        }


        
        

        Console.WriteLine(ss);
        input = Console.ReadLine();

    }
}