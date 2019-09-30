using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static int Tribonach(int count, int a1, int a2, int a3)
    {
        if(count < 3)
            return 0;
        else if(count == 3)
            return a3;
        else
            return Tribonach(count - 1, a2, a3, (a1 + a2 + a3) %  10007) ;
    }
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int a3 = n < 3 ? 0 : 1;
        for(int count = 3, a1 = 0, a2 = 0; count < n; count++)
        {
            int temp = (a1 + a2 + a3) % 10007;
            a1 = a2;
            a2 = a3;
            a3 = temp;
        }
        Console.WriteLine(a3);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}