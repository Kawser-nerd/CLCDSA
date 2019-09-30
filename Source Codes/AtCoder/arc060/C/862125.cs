using System;
using System.Text;


class A {
    int N;
    int maxN = 100005;
    long L;
    int Q;
    long[] x;
    int[,] l;
    public A(){
        x = new long[maxN];
        l = new int[20,maxN];
    }
    public int calc(int a, int b){
        if(a==b) return 0;
        if(b<=l[0,a]) return 1;
        for(int i=0;i<19;i++){
            int h = (int)(1<<i);
            if(l[i,a]<=b && l[i+1,a]>b){
                return h+calc(l[i,a],b);
            }
        }
        return -1;
    }
    public string F(){
        return Console.ReadLine();
    }
    public void run(){
        N = int.Parse(F());
        string[] ss = F().Split(' '); 
        for(int i=0;i<N;i++){
            x[i] = long.Parse(ss[i]);
        }
        x[N] = x[N-1]+1;
        N = N+1;
        L = long.Parse(F());
        Q = int.Parse(F());
        
        
        int p = 1;
        for(int i=0;i<N;i++){
            while(p<N && x[p]-x[i] <= L) p++;
            p--;
            l[0,i] =  p;
        }
        
        for(int k=1;k<20;k++){
            for(int i=0;i<N;i++){
                l[k,i] = l[k-1,l[k-1,i]];
            }
        }
        
        StringBuilder sb = new StringBuilder("", 12*Q);
        for(int _=0;_<Q;_++){
            ss = F().Split(' '); 
            int a = int.Parse(ss[0])-1;
            int b = int.Parse(ss[1])-1;
            if(a>b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            sb.Append(calc(a,b)+"\n");
        }
        Console.WriteLine(sb.ToString());
    }
}


class Program {
    static void Main(string[] args){
        A a = new A();
        a.run();    
    }
}