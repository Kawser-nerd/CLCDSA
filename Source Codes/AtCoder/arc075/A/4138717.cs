using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long ans = 0;
        long min = 99999999999;
        for(int i = 0; i < n; i++)
        {
            long tmp = long.Parse(Console.ReadLine());
            ans += tmp;
            if(tmp % 10 != 0){
                min = Math.Min(min, tmp);
            }
        }

        if(min == 99999999999)
        {
            Console.WriteLine(0);
            return;
        }
        
        if(ans % 10 == 0)
        {
            Console.WriteLine(ans - min);
        }
        else
        {
            Console.WriteLine(ans);
        }

    }
}