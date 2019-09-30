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
            string[] str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            
            int[] tower = new int[1000];
            tower[0] = 1;
            for(int i = 1 ; i < 1000 ; i++)
            {
                tower[i] = tower[i-1] + i+1;
               
            }
            int ans = tower[b-a-1] - b;
            Console.WriteLine(ans);
            
        }
    }
}