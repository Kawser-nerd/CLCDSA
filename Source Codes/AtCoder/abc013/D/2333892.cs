using System;
using System.Collections.Generic;
using System.Linq;

namespace app
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] str;
            str = Console.ReadLine().Split(' ');
            int N = int.Parse(str[0]), M = int.Parse(str[1]), D = int.Parse(str[2]);
            str = Console.ReadLine().Split(' ');
            int[] A = new int[M];
            for (int i = 0; i < M; i++) {
                A[i] = int.Parse(str[i]);
            }

            int[] pos = new int[N];
            for (int i = 0; i < N; i++) pos[i] = i;

            int d = D;
            int[] posD = new int[N];
            for (int i = 0; i < N; i++) posD[i] = i;
            for (int i = 0; i < M; i++) {
                int t = posD[A[i]-1];
                posD[A[i]-1] = posD[A[i]];
                posD[A[i]] = t;
            }

            while (d > 0) {
                if (d % 2 == 0) {
                    int[] tmp = new int[N];
                    for (int j = 0; j < N; j++) {
                        tmp[j] = posD[posD[j]];
                    }
                    posD = tmp;
                    d /= 2;
                } else {
                    int[] tmp = new int[N];
                    for (int j = 0; j < N; j++) {
                        tmp[j] = pos[posD[j]];
                    }
                    pos = tmp;
                    d -= 1;
                }                
            } 
            
            int[] goal = new int[N];
            for (int j = 0; j < N; j++) goal[pos[j]] = j+1;
            for (int j = 0; j < N; j++) Console.WriteLine(goal[j]);
        }
    }
}