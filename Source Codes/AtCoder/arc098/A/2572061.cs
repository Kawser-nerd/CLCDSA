using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Globalization;
using static System.Console;
using static System.Math;


namespace templete
{
    class arc98_c
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string str = Console.ReadLine();

            int[] west = new int[n];
            int[] east = new int[n];

            int count=0;
            for(int i=0; i<n; i++){
                if(str[i] == 'W')count++;
                west[i] = count;
            }

            count=0;
            for(int i=n-1; i>=0; i--){
                if(str[i] == 'E')count++;
                east[i] = count;
            }

            int min=int.MaxValue;
            for(int i=0; i<n; i++){
                int tmp=0;
                if(i == n-1){
                    tmp = west[i]+0;
                }else if(i == 0){
                    tmp = 0+east[i];
                }else{
                    tmp = west[i-1]+east[i+1];
                }
                min = Min(min, tmp);
            }
            WriteLine(min);
        }

        static void Swap<T>(ref T lhs, ref T rhs)
        {
            T temp;
            temp = lhs;
            lhs = rhs;
            rhs = temp;
        }
    }
}