using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;



static class AT {
    static int N;
    static int[] A;
    static void Main() {
        N = int.Parse(Console.ReadLine());
        A = new int[N];
       int []B= new int[N];
        Dictionary<int, int> d = new Dictionary<int, int>();
        for (int i = 0; i < N; i++) {
         int j=int.Parse(Console.ReadLine());
            A[i] = j;
            B[i] = j;
            d.Add(j, i);
        }
        int c = 0;
        Array.Sort(B);
        for(int i = 0; i < N; i++) {
         if(d[B[i]] % 2 != i % 2) {
                c++;
            }
        }
        Console.WriteLine(c/2);
    }
}