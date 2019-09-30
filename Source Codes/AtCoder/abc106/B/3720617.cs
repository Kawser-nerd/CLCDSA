using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int cnt = 0;
            int a = 0;
            
            
            for(int i = 1 ; i <= n ; i+=2)
            {
                a = 0;
                for(int j = 1 ; j <= i ; j+=2)
                {
                    if(i % j == 0) a++;
                }
                if(a==8) cnt++;
            }
            Console.WriteLine(cnt);
        }
    }
}