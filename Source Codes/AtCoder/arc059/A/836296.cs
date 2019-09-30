using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;

class Program{
    static void Main(){
        int N = int.Parse(Console.ReadLine());
        string[] inputs = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        for(int i = 0; i < N; i++){
            a[i] = int.Parse(inputs[i]);
        }
        int avg = (int)Math.Round(a.Average(), MidpointRounding.AwayFromZero);
        int cost = 0;
        for(int i = 0; i < N; i++){
            if(a[i] != avg){
                cost += (int)Math.Pow((a[i] - avg), 2);
            }
        }
        Console.WriteLine(cost);
    }
}