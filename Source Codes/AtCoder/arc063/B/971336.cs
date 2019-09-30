using System;
using System.Collections.Generic;
class Solve{
    int N;
    long T;
    long[] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long min = 1000000001;
        long max = 0;
        int count = 0;
        for(int i=0;i<N;i++){
            if(a[i] < min){
                min = a[i];
            }
            else if(a[i] - min == max){
                count++;
            }
            else if(a[i] - min > max){
                count = 1;
                max = a[i] - min;
            }
        }
        Console.WriteLine(count);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        T = Int64.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        a = new long[N];
        for(int i=0;i<N;i++){
            a[i] = Int64.Parse(str[i]);
        }
    }    
}