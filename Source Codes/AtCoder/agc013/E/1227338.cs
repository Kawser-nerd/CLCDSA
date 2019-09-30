using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    long[,] E;
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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        E = new long[3,3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                E[i,j] = i == j ? 1 : 0;
            }
        }
        long[,] T = new long[3,3];
        long[,] F = new long[3,3];
        T[0,0] = 2;
        F[0,0] = 1;
        T[0,1] = 1;
        F[0,1] = 1;
        T[1,0] = 3;
        T[1,1] = 1;
        F[1,1] = 1;
        T[1,2] = 1;
        F[1,2] = 1;
        T[2,0] = 2;
        T[2,2] = 1;
        F[2,2] = 1;
        long X = 1;
        long Y = 3;
        long Z = 2;
        str = Console.ReadLine().Split(' ');
        long[,] C = E;
        for(int i=0;i<M;i++){
            long[,] Matrix = Pow(T,int.Parse(str[i])-(i == 0 ? 0 : int.Parse(str[i-1]))-1);
            C = Mul(Matrix,C);
            C = Mul(F,C);
        }
        {
            long[,] Matrix = Pow(T,N-1-(M == 0 ? 0 : int.Parse(str[M-1])));
            C = Mul(Matrix,C);
        }
        /*for(int i=1;i<N;i++){
            long X0,Y0,Z0;
            if(c != M && int.Parse(str[c]) == i){
                c++;
                X0 = X+Y;
                Y0 = Y+Z;
                Z0 = Z;
            }
            else{
                X0 = 2*X+Y;
                Y0 = Y+Z+3*X;
                Z0 = Z+2*X;
            }
            X = X0 % Define.mod;
            Y = Y0 % Define.mod;
            Z = Z0 % Define.mod;
            Console.WriteLine(X+" "+Y+" "+Z);
        }*/
        sb.Append((X*C[0,0]+Y*C[0,1]+Z*C[0,2])%Define.mod+"\n");
    }
    long[,] Mul(long[,] a,long[,] b){
        long[,] c = new long[3,3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                long d = 0;
                for(int k=0;k<3;k++){
                    d += a[i,k]*b[k,j]%Define.mod;
                }
                c[i,j] = d % Define.mod;
            }
        }
        return c;
    }
    long[,] Pow(long[,] a,long e){
        if(e == 0){
            return E;
        }
        else if(e%2 == 0){
            long[,] b = Mul(a,a);
            return Pow(b,e/2);
        }
        else{
            return Mul(Pow(a,e-1),a);
        }
    }
}
public static class Define{
    public const long mod = 1000000007;
}