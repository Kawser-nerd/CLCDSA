using System;
using System.Collections.Generic;
class Solve{
    int N;
    long[] s;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        Generateprimenumber p1 = new Generateprimenumber(2154);
        Generateprimenumber p2 = new Generateprimenumber(100000);
        Map m1;
        Map m2;
        List<long> e = new List<long>();
        List<long> q = new List<long>();
        {
            long[] pp = new long[p2.length];
            for(int i=0;i<p2.length;i++){
                pp[i] = (long)(p2.p[i])*(long)(p2.p[i]);
            }
            m1 = new Map(pp,p2.p);
        }
        {
            long[] f = new long[N];
            for(int i=0;i<N;i++){
                long a = s[i];
                for(int j=0;j<p1.length;j++){
                    long k = (long)p1.p[j]*(long)p1.p[j]*(long)p1.p[j];
                    while(true){
                        if(a%k == 0){
                            a /= k;
                        }
                        else{
                            break;
                        }
                    }
                }
                f[i] = a;
            }
            Array.Sort(f);
            int count = 1;
            List<int> d = new List<int>();
            e.Add(f[0]);
            for(int i=1;i<N;i++){
                if(f[i-1] == f[i]){
                    count++;
                }
                else{
                    d.Add(count);
                    count = 1;
                    e.Add(f[i]);
                }
            }
            d.Add(count);
            m2 = new Map(e.ToArray(),d.ToArray());
        }
        for(int i=0;i<e.Count;i++){
            long a = e[i];
            long b = 1;
            long c;
            bool y = false;
            try{
                checked{
                    for(int j=0;j<p1.length;j++){
                        if(a%((long)p1.p[j]*(long)p1.p[j]) == 0){
                            a /= ((long)p1.p[j]*(long)p1.p[j]);
                            b *= p1.p[j];
                        }
                        else if(a%p1.p[j] == 0){
                            a /= p1.p[j];
                            b *= ((long)p1.p[j]*(long)p1.p[j]);
                        }
                    }
                    c = m1.Get(a);
                    if(c == -1){
                        c = a*a;
                    }
                    b *= c;
                }
            }
            catch(OverflowException ex){
                y = true;
            }
            if(y){
                q.Add(-1);
            }
            else{
                q.Add(b);
            }
        }
        {
            int count = 0;
            if(e[0] == 1){
                count++;
                for(int i=1;i<e.Count;i++){
                    int y = m2.Get(q[i]);
                    if(y == -1){
                        count += m2.data[i];
                    }
                    else if(e[i] < q[i]){
                        count += m2.data[i] <= y ? y : m2.data[i];
                    }
                }
            }
            else{
                for(int i=0;i<e.Count;i++){
                    int y = m2.Get(q[i]);
                    if(y == -1){
                        count += m2.data[i];
                    }
                    else if(e[i] < q[i]){
                        count += m2.data[i] <= y ? y : m2.data[i];
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        s = new long[N];
        for(int i=0;i<N;i++){
            s[i] = Int64.Parse(Console.ReadLine());
        }
    }    
}
class Map{
    long[] trees;
    public int[] data;
    int length;
    public Map(long[] t,int[] d){
        trees = t;
        length = trees.Length;
        data = d;
        Array.Sort(trees,(a,b) => Compare(a,b));
    }
    public int Compare(long a,long b){
        //??????
        if(a > b){
            return 1;
        }
        else if(a < b){
            return -1;
        }
        else{
            return 0;
        }
    }
    public int Get(long a){
        int min = 0;
        int max = length-1;
        while(min != max){
            if(Compare(a,trees[(min+max)/2]) <= 0){
                max = (min+max)/2;
            }
            else{
                min = (min+max)/2+1;
            }
        }
        if(trees[min] == a){
            return data[min];
        }
        else{
            return -1;
        }
    }
    public void Set(long a,int b){
        int min = 0;
        int max = length-1;
        while(min != max){
            if(Compare(a,trees[(min+max)/2]) <= 0){
                max = (min+max)/2;
            }
            else{
                min = (min+max)/2+1;
            }
        }
        data[min] = b;
    }
}
class Generateprimenumber{
    public int[] p;
    public int length;
    public Generateprimenumber(int n){
        bool[] a = new bool[n+1];
        List<int> pp = new List<int>();
        int j = 2;
        for(int i=0;i<n+1;i++){
            a[i] = true;
        }
        while(j<=n){
            if(a[j]){
                pp.Add(j);
                for(int i=j;(long)i*(long)j<=(long)n;i++){
                    a[i*j] = false;
                }
            }
            j++;
        }
        length = pp.Count;
        p = pp.ToArray();
    }
}