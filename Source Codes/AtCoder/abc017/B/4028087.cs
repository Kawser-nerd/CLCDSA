using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        string input = Console.ReadLine();
        for(int i = 0; i < input.Length; i++)
        {
            if("oku".Contains(input[i]))
                continue;
            if(i + 1 < input.Length && input[i] == 'c' && input[i + 1] == 'h')
            {
                i++;
                continue;
            }
            Console.WriteLine("NO");
            return;
        }
        Console.WriteLine("YES");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}