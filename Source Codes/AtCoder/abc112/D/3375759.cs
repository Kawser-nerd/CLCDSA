using System;
using System.Collections.Generic;
using System.Linq;
class P{
    static void Main(){
        string[] s = Console.ReadLine().Split();
        int n = int.Parse(s[0]);
        int m = int.Parse(s[1]);
        int u = m / n;
        for (int i = u;i > 0;i--){
            if (m % i == 0){
                Console.WriteLine(i);
                return;
            }
        }
    }
}