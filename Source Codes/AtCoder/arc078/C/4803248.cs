using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;


static class P
{
    static void Main()
    {
        //????????????
        long res = 0;
        while (true)
        {
            int valid = 10;
            int invalid = res == 0 ? 0 : -1;
            while (valid - invalid > 1)
            {
                var mid = (valid + invalid) / 2;
                Console.WriteLine($"? {(res * 10 + mid).ToString().PadRight(11, '9')}");
                var ans = Console.ReadLine();
                if (ans == "Y") valid = mid;
                if (ans == "N") invalid = mid;
            }
            if (invalid == -1)
            {
                Console.WriteLine($"? {"".PadRight(res.ToString().Length, '9')}");
                var ans = Console.ReadLine();
                if(ans == "Y")
                {

                    Console.WriteLine($"! {res}");
                    break;
                }
            }
            res = (res * 10 + valid);
        }

    }
}