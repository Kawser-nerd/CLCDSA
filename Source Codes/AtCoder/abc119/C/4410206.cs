using System;
using System.Linq;
public class Hello{
    //imit
    static int A,B,C,N;
    
    static int[] l;
    
    public static void Main(){
        var s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        N = s[0];
        A = s[1];
        B = s[2];
        C = s[3];
        
        l = new int[N];
        
        for(var i = 0;i < N;i++){
            l[i] = int.Parse(Console.ReadLine());
        }
        
        Console.WriteLine(Calc(0,0,0,0));
    }
    
    static int Calc(int cnt,int a,int b,int c){
        if(cnt == N){
            return a == 0 || b == 0 || c == 0 ? 1000000 : Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c) - 30;
        }
        
        var pattern = new int[4];
        pattern[0] = Calc(cnt + 1,a,b,c);
        pattern[1] = Calc(cnt + 1,a + l[cnt],b,c) + 10;
        pattern[2] = Calc(cnt + 1,a,b + l[cnt],c) + 10;
        pattern[3] = Calc(cnt + 1,a,b,c + l[cnt]) + 10;
        
        return pattern.Min();
    }
}