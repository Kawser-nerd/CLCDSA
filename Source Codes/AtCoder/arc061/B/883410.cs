using System;
using System.Collections.Generic;
class Solve{
    public long H;
    public long W;
    public int N;
    public long[] a;
    public long[] b;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        long[] sort;
        int[] ans = new int[9];
        long[] all = new long[9*N];
        int sum = 0;
        int count = 0;
        for(int i=0;i < 9;i++){
            ans[i] = 0;
        }
        for(int i=0;i < N;i++){
            for(int j = -1;j < 2;j++){
                if(b[i]+j < W-1 && b[i]+j > 0){
                    for(int k = -1;k < 2;k++){
                        if(a[i]+k < H-1 && a[i]+k > 0){
                            all[count] = (b[i]+j)*H+a[i]+k;
                            count++;
                        }
                    }
                }
            }
        }
        sort = new long[count];
        for(int i=0;i < count;i++){
            sort[i] = all[i];
        }
        Array.Sort(sort);
        for(int i = 0;i < count-1;i++){
            int c = 1;
            while(i < count-1 && sort[i] == sort[i+1]){
                i++;
                c++;
            }
            if(i == count-2){
                ans[0]++;
            }
            ans[c-1]++;
        }
        for(int i=0;i < 9;i++){
            sum += ans[i];
        }
        Console.WriteLine((H-2)*(W-2)-sum);
        for(int i=0;i < 9;i++){
            Console.WriteLine(ans[i]);
        }
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        H = int.Parse(str[0]);
        W = int.Parse(str[1]);
        N = int.Parse(str[2]);
        a = new long[N];
        b = new long[N];
        for(int i = 0;i < N;i++){
            str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
        }
    }    
}