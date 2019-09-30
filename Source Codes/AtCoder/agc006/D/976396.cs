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
        int f = 2;
        int l = 2*N-2;
        while(f != l){
            int c = (f+l+1)/2;
            if(check(c)){
                f = c;
            }
            else{
                l = c-1;
            }
        }
        Console.WriteLine(f);
    }
    bool check(int j){
        if(a[N-1] >= j && (a[N] >= j || a[N-2] >= j)){
            return true;
        }
        if(a[N-1] < j && (a[N] < j || a[N-2] < j)){
            return false;
        }
        bool b = (a[N-1] < j);
        for(int i=1;i<N;i++){
            if(b && (a[N-1-i] < j || a[N-1+i] < j)){
                return false;
            }
            if(!b && (a[N-1-i] >= j || a[N-1+i] >= j)){
                return true;
            }
            b = !b;
        }
        return !b;
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        a = new int[2*N-1];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<2*N-1;i++){
            a[i] = int.Parse(str[i]);
        }
    }    
}