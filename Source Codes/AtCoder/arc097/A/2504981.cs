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
    class arc97_c
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int k = int.Parse(Console.ReadLine());
            List<string> list = new List<string>();
            int i,j;
            int n = str.Length;

            for(i=0; i<n; i++){
                for(j=0; j<n-i; j++){
                    if(j+1 <= 5){
                        list.Add(str.Substring(i, j+1));
                    }
                }
            }

            string[] arr = list.Distinct().ToArray();
            Array.Sort(arr);

            //foreach(var item in arr){
            //    WriteLine(item);
            //}
            WriteLine(arr[k-1]);

        }
    }
}