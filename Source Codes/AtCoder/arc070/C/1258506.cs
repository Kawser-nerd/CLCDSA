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
        int N = int.Parse(Console.ReadLine());
        int[] l = new int[N];
        int[] r = new int[N];
        for(int i=0;i<N;i++){
            string[] str = Console.ReadLine().Split(' ');
            l[i] = int.Parse(str[0]);
            r[i] = int.Parse(str[1]);
        }
        AbsoluteSum Ab = new AbsoluteSum(N);
        Ab.Add(l[0]);
        for(int i=1;i<N;i++){
            Ab.Min(l[i]-r[i],r[i-1]-l[i-1]);
            Ab.Add(l[i]);
        }
        sb.Append(Ab.GetMin()+"\n");
    }
}
class AbsoluteSum{
    long minValue;
    Heap Lheap;
    long LS;
    Heap Rheap;
    long RS;
    public AbsoluteSum(int maxsize){
        minValue = 0;
        Lheap = new Heap(maxsize*2,false);
        Rheap = new Heap(maxsize*2,true);
        LS = 0;
        RS = 0;
    }
    public void Add(long X){
        if(Lheap.size != 0 && Lheap.Get() + LS >= X){
            minValue += Lheap.Get() + LS - X;
            Rheap.push(Lheap.pop() + LS - RS);
            Lheap.push(X-LS);
            Lheap.push(X-LS);
        }
        else if(Rheap.size != 0 && Rheap.Get() + RS <= X){
            minValue += X - Rheap.Get() - RS;
            Lheap.push(Rheap.pop() + RS - LS);
            Rheap.push(X-RS);
            Rheap.push(X-RS);
        }
        else{
            Lheap.push(X-LS);
            Rheap.push(X-RS);
        }
    }
    public void Min(long a,long b){
        LS += a;
        RS += b;
    }
    public long GetMin(){
        return minValue;
    }
}
class Heap{
    public int size;
    long[] obj;
    bool B;
    public Heap(int maxsize,bool b0){
        size = 0;
        B = b0;
        obj = new long[maxsize];
    }
    //??????a<=b
    public bool Compare(long a,long b){
        return (B && a<=b) || (!B && a>=b);
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
    public long Get(){
        return obj[0];
    }
}