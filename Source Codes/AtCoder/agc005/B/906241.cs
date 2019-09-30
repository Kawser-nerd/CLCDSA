using System;
using System.Collections.Generic;
class Solve{
    int N;
    int[] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] sort = new int[N];
        int[] linka = new int[N];
        int[] linkb = new int[N];
        long count = 0;
        for(int i=0;i < N;i++){
            sort[i] = i;
            linka[i] = i+1;
            linkb[i] = i-1;
        }
        Array.Sort(sort,(c,b) => a[b] - a[c]);
        for(int i=0;i<N;i++){
            int min = linkb[sort[i]];
            int max = linka[sort[i]];
            if(min != -1){
                linka[min] = max;
            }
            if(max != N){
                linkb[max] = min;
            }
            count += (long)(max-sort[i])*(long)(sort[i]-min)*(long)a[sort[i]];
        }
        Console.WriteLine(count);
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = int.Parse(str[i]);
        }
    }    
}