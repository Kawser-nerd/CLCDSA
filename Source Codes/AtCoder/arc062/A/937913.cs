using System;
using System.Collections.Generic;
class Solve{
    int N;
    int[] T;
    int[] A;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long a = 1;
        long b = 1;
        for(int i=0;i<N;i++){
            if((a-1)/T[i] >= (b-1)/A[i]){
                b = ((a-1)/T[i]+1)*A[i];
                a = ((a-1)/T[i]+1)*T[i];
            }
            else{
                a = ((b-1)/A[i]+1)*T[i];
                b = ((b-1)/A[i]+1)*A[i];
            }
        }
        Console.WriteLine(a+b);
    }
    void getinput(){
        string[] str;
        N = int.Parse(Console.ReadLine());
        T = new int[N];
        A = new int[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            T[i] = int.Parse(str[0]);
            A[i] = int.Parse(str[1]);
        }
    }    
}