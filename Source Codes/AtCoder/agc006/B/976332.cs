using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    int x;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] X = new int[2*N-1];
        if(x == 1 || x == 2*N-1){
            Console.WriteLine("No");
            return;
        }
        else{
            Console.WriteLine("Yes");
            if(x == 2){
                X[N-1] = x;
                X[N-2] = x-1;
                for(int i=0;i<2*N-1;i++){
                    if(i<N-2){
                        X[i] = i+3;
                    }
                    if(i>N-1){
                        X[i] = i+1;
                    }
                }
            }
            else{
                X[N-1] = x;
                X[N-2] = x+1;
                X[N-3] = x-1;
                X[N] = x-2;
                for(int i=0;i<2*N-1;i++){
                    if((i<N-3 && i<x-3)||(i>N && i>x)){
                        X[i] = i+1;
                    }
                    if(i<N-3 && i>=x-3){
                        X[i] = i+5;
                    }
                    if(i>N && i<=x){
                        X[i] = i-3;
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<2*N-1;i++){
            sb.Append(X[i]+"\n");
        }
        Console.Write(sb.ToString());
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        x = int.Parse(str[1]);
    }    
}