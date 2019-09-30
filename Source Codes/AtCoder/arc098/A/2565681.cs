using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(ReadLine());
        string s = ReadLine();
        int c = 0, minC = n;

        for(int i = 1;i < n; i++)
        {
            if (s[i] == 'E') c++;
        }
        if (minC > c) minC = c;

        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == 'W') c++;
            if (s[i] == 'E') c--;
            if (minC > c)
            {
                minC = c;
                if (minC == 0) break;
            }
            
        }
        WriteLine(minC);
    }
}