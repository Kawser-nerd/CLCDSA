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
        int sum = 0;
        long count = 0;
        int ave;
        for(int i=0;i<N;i++){
            sum += a[i];
        }
        ave = sum/N+(sum%N > N/2 ? 1 : 0);
        for(int i=0;i<N;i++){
            count += (a[i]-ave)*(a[i]-ave);
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