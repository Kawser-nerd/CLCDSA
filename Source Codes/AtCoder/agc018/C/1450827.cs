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
        int X = int.Parse(str[0]);
        int Y = int.Parse(str[1]);
        int Z = int.Parse(str[2]);
        int N = X+Y+Z;
        long count = 0;
        long[] A = new long[N];
        long[] B = new long[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            long C = int.Parse(str[2]);
            count += C;
            A[i] = int.Parse(str[0])-C;
            B[i] = int.Parse(str[1])-C;
        }
        int[] order = new int[N];
        for(int i=0;i<N;i++){
            order[i] = i;
        }
        Array.Sort(order,(x,y)=>A[x]-B[x] > A[y]-B[y] ? -1 : (A[x]-B[x] == A[y]-B[y] ? 0 : 11));
        {
            long[] AA = new long[N];
            long[] BB = new long[N];
            for(int i=0;i<N;i++){
                AA[i] = A[order[i]];
                BB[i] = B[order[i]];
            }
            A = AA;
            B = BB;
        }
        long sum = 0;
        long[] AX = new long[N];
        Heap H = new Heap(N);
        for(int i=0;i<X;i++){
            sum += A[i]; 
            H.push(A[i]);
        }
        AX[X-1] = sum;
        for(int i=X;i<N;i++){
            sum += A[i];
            H.push(A[i]);
            sum -= H.pop();
            AX[i] = sum;
        }
        long[] BY = new long[N];
        sum = 0;
        H = new Heap(N);
        for(int i=0;i<Y;i++){
            sum += B[N-1-i]; 
            H.push(B[N-1-i]);
        }
        BY[Y-1] = sum;
        for(int i=Y;i<N;i++){
            sum += B[N-1-i];
            H.push(B[N-1-i]);
            sum -= H.pop();
            BY[i] = sum;
        }
        long max = AX[X-1] + BY[N-X-1];
        for(int i=X;i<N-Y;i++){
            max = Math.Max(max,AX[i] + BY[N-i-2]);
        }
        count += max;
        sb.Append(count+"\n");
    }
}
class Heap{
    public int size;
    long[] obj;

    public Heap(int maxsize){
        size = 0;
        obj = new long[maxsize];
    }
    public bool Compare(long a,long b){
        return a <= b;
    }
    public void push(long a){
        int i = size;
        size++;
        while(i > 0){
            int p = (i - 1)/2;
            if(Compare(obj[p],a)){
                obj[i] = a;
                break;
            }
            obj[i] = obj[p];
            i = p;
        }
        if(i == 0){
            obj[0] = a;
        }
    }
    public long pop(){
        long t = obj[0];
        int i = 0;
        size--;
        while(2*i+1 < size){
            int p = 2*i+1;
            if(p+1 < size && Compare(obj[p+1],obj[p])){
                p++;
            }
            if(Compare(obj[p],obj[size])){
                obj[i] = obj[p];
                i = p;
            }
            else{
                obj[i] = obj[size];
                break;
            }
        }
        if(2*i+1 >= size){
            obj[i] = obj[size];
        }
        return t;
    }
}