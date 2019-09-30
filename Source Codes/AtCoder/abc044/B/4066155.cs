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

        List<char> cc = new List<char>();
        cc.AddRange(input);

        while (cc.Count != 0)
        {
            char c = cc.First();
            cc.Remove(c);
            if(!cc.Remove(c))
            {
                Console.WriteLine("No"); return;
            }

        }
        Console.WriteLine("Yes"); return;



    }
}