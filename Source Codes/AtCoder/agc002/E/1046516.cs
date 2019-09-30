using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N;
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        for(int j=0;j<N;j++){
            a[j] = int.Parse(str[j]);
        }
        Array.Sort(a,(x,y) => y - x);
        int i = 0;
        while(i < N-1 && a[i+1] > i+1){
            i++;
        }
        if((a[i] - i) % 2 == 0){
            sb.Append("First\n");
        }
        else{
            int c = 1;
            while(i+c < N && i+1 == a[i+c]){
                c++;
            }
            if(c % 2 == 0){
                sb.Append("First\n");
            }
            else{
                sb.Append("Second\n");
            }
        }
    }    
}