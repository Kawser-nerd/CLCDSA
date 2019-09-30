using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[2]);
        long RR = int.Parse(str[0]);
        long C = int.Parse(str[1]);
        int[] A;
        {
            int count = 0;
            List<long> Left = new List<long>();
            List<long> Right = new List<long>();
            List<long> Top = new List<long>();
            List<long> Bottom = new List<long>();
            List<int> left = new List<int>();
            List<int> right = new List<int>();
            List<int> top = new List<int>();
            List<int> bottom = new List<int>();
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                long X1 = int.Parse(str[0]);
                long Y1 = int.Parse(str[1]);
                long X2 = int.Parse(str[2]);
                long Y2 = int.Parse(str[3]);
                bool bb = X1 == 0 || X1 == RR || Y1 == 0 || Y1 == C;
                bool c = X2 == 0 || X2 == RR || Y2 == 0 || Y2 == C;
                if(bb && c){
                    count++;
                    if(X1 == 0){
                        Left.Add(Y1);
                        left.Add(i);
                    }
                    else if(X1 == RR){
                        Right.Add(Y1);
                        right.Add(i);
                    }
                    else if(Y1 == 0){
                        Bottom.Add(X1);
                        bottom.Add(i);
                    }
                    else{
                        Top.Add(X1);
                        top.Add(i);
                    }
                    if(X2 == 0){
                        Left.Add(Y2);
                        left.Add(i);
                    }
                    else if(X2 == RR){
                        Right.Add(Y2);
                        right.Add(i);
                    }
                    else if(Y2 == 0){
                        Bottom.Add(X2);
                        bottom.Add(i);
                    }
                    else{
                        Top.Add(X2);
                        top.Add(i);
                    }
                }
            }
            long[] L = Left.ToArray();
            long[] R = Right.ToArray();
            long[] T = Top.ToArray();
            long[] B = Bottom.ToArray();
            int[] l = left.ToArray();
            int[] r = right.ToArray();
            int[] t = top.ToArray();
            int[] b = bottom.ToArray();
            Array.Sort(L,l);
            Array.Sort(R,r);
            Array.Sort(T,t);
            Array.Sort(B,b);
            A = new int[2*count];
            count = 0;
            for(int i=0;i<l.Length;i++){
                A[count] = l[i];
                count++;
            }
            for(int i=0;i<t.Length;i++){
                A[count] = t[i];
                count++;
            }
            for(int i=0;i<r.Length;i++){
                A[count] = r[r.Length-1-i];
                count++;
            }
            for(int i=0;i<b.Length;i++){
                A[count] = b[b.Length-1-i];
                count++;
            }
        }
        int[] stack = new int[2*N];
        int p = 0;
        for(int i=0;i<A.Length;i++){
            stack[p] = A[i];
            p++;
            if(p != 1 && stack[p-1] == stack[p-2]){
                p -= 2;
            }
        }
        if(p == 0){
            sb.Append("YES\n");
        }
        else{
            sb.Append("NO\n");
        }
    }
}