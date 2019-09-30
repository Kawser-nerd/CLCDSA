using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program{
    static void Main(){
        int n = int.Parse(Console.ReadLine());
        if (n % 2 == 0){
            Console.WriteLine(n * (n - 1) / 2 - n / 2);
            for (int i = 1;i <= n;i++){
                for (int j = i + 1;j <= n;j++){
                    if (i + j == n + 1) continue;
                    Console.WriteLine("{0} {1}",i,j);
                }
            }
            return;
        }
        Console.WriteLine(n * (n - 1) / 2 - n / 2);
        for (int i = 1;i < n;i++){
            for (int j = i + 1;j < n;j++){
                if (i + j == n) continue;
                Console.WriteLine("{0} {1}",i,j);
            }
        }
        for (int i = 1;i < n;i++)
            Console.WriteLine("{0} {1}",i,n);
    }
}