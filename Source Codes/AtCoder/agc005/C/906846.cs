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
        int min = N;
        int max = 0;
        int[] b;
        for(int i=0;i<N;i++){
            if(min > a[i])
                min = a[i];
            if(max < a[i])
                max = a[i];
        }
        b = new int[max-min+1];
        for(int i=0;i<max-min+1;i++){
            b[i] = 0;
        }
        for(int i=0;i<N;i++){
            b[a[i]-min]++;
        }
        if((b[0] == 1 && max == 2*min) || (b[0] == 2 && max == 2*min-1)){
            int i = 1;
            while(i < max-min+1){
                if(b[i] <= 1){
                    Console.WriteLine("Impossible");
                    return;
                }
                i++;
            }
        }
        else{
            Console.WriteLine("Impossible");
                    return;
        }
        Console.WriteLine("Possible");
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