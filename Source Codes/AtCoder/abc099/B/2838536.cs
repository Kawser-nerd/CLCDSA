using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;


namespace atPra
{
    class Class1
    {
        static void Main()
        {
            string[] str = Console.ReadLine().Split(null);
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            int diff = b - a;
            int x = calc(diff)-b;
            Console.WriteLine(x);
        }

        static int calc(int y){
            int sum = 0;
            for (int i = 1; i <= y;i++){
                sum += i;
            }
            return sum;
        }
    }
}