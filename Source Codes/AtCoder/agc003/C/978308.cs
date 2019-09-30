using System;
using System.Collections.Generic;
class Solve{
    int N;
    long[] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] b = new int[N];
        for(int i=0;i<N;i++){
            b[i] = i;
        }
        int count = 0;
        Array.Sort(b,(i,j) => c(i,j));
        for(int i=0;i<N;i++){
            if(b[i] % 2 != i % 2){
                count++;
            }
        }
        Console.WriteLine(count/2);
    }
    int c(int i,int j){
        if(a[i] - a[j] > 0){
            return 1;
        }
        else if(a[i] == a[j]){
            return 0;
        }
        else{
            return -1;
        }
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        a = new long[N];
        for(int i=0;i<N;i++){
            a[i] = Int64.Parse(Console.ReadLine());
        }
    }
}