using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        string str = Console.ReadLine();
        string out1 = "";
        int inde = 0;
        int others = 0;
        //foreach (char c in str)
        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] == '(')
            { 
                out1 = out1 + "(";
                others = others + 1;
            }
            if (str[i] == ')')
            {
                if (others == 0)
                {
                    out1 = "(" + out1 + ")";
                }
                else
                {
                    out1 = out1 + ")";
                    others = others - 1;
                }
            }
        }
        for (int i = 0; i < others; i++)
        {
            out1 = out1 + ")";
        }
        Console.WriteLine(out1);
    }
}