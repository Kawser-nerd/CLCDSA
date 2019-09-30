using System;
using System.Collections.Generic;
class Solve{
    public int n;
    public long x;
    public long[] a;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long[] bonus = new long[n-1];
        long ans = 0;
        long temp;
        for(int i = 0;i < n-1;i++){
            bonus[i] = 0;
        }
        for(int i = 0;i < n;i++){
            long min;
            min = a[i];
            for(int j = 1;j < i+1;j++){
                if(min > a[i-j]){
                    bonus[j-1] += min - a[i-j];
                    min = a[i-j];
                }
            }
            for(int j = i+1;j < n;j++){
                if(min > a[i-j+n]){
                    bonus[j-1] += min - a[i-j+n];
                    min = a[i-j+n];
                }
            }
        }
        for(int i = 0;i < n;i++){
            ans += a[i];
        }
        temp = ans;
        for(int i = 0;i < n-1;i++){
            temp += x;
            temp -= bonus[i];
            if(ans > temp){
                ans = temp;
            }
        }
        Console.WriteLine(ans);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        n = int.Parse(str[0]);
        x = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        a = new long[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(str[i]);
        }
    }    
}