using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    long N,K;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        Generateprimenumber P = new Generateprimenumber(100000);
        long count = 0;
        long[] div = P.Divisor(N);
        Array.Sort(div);
        Map m = new Map(div);
        for(int i=0;i<div.Length;i++){
            long[] div2 = P.Divisor(div[i]);
            long c = Pow(K,(div[i]+1)/2);
            for(int j=0;j<div2.Length;j++){
                c = (c + Define.mod - m.Get(div2[j]))%Define.mod;
            }
            m.Set(div[i],c);
            if(div[i] % 2 == 0){
                c = c * (div[i]/2) % Define.mod;
            }
            else{
                c = c * div[i] % Define.mod;
            }
            count = (count + c) % Define.mod; 
        }
        sb.Append(count+"\n");
    }
    public long Pow(long n,long k){
        if(k == 0){
            return 1;
        }
        else if(k % 2 == 0){
            long t = Pow(n,k/2);
            return t*t%Define.mod;
        }
        else{
            return n*Pow(n,k-1)%Define.mod;
        }
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        K = int.Parse(str[1]);
    }    
}
class Generateprimenumber{
    public long[] p;
    public int length;
    public Generateprimenumber(int n){
        bool[] a = new bool[n+1];
        List<long> pp = new List<long>();
        int j = 2;
        for(int i=0;i<n+1;i++){
            a[i] = true;
        }
        while(j<=n){
            if(a[j]){
                pp.Add(j);
                for(int i=j;(long)i*(long)j<=n;i++){
                    a[i*j] = false;
                }
            }
            j++;
        }
        length = pp.Count;
        p = pp.ToArray();
    }
    public long[] Divisor(long n){
        List<int> pp = new List<int>();
        long num = n;
        int count = 1;
        bool last = false;
        for(int i=0;p[i]*p[i] <= num;i++){
            int j=0;
            while(num % p[i] == 0){
                num /= p[i];
                j++;
            }
            pp.Add(j);
            count *= j+1; 
        }
        if(num != 1){
            pp.Add(1);
            count *= 2;
            last = true;
        }
        long[] div = new long[count];
        for(int i=0;i<count;i++){
            long x = 1;
            int y = i;
            int z = count;
            for(int j=0;j<pp.Count;j++){
                z /= pp[j]+1;
                int k = y/z;
                y %= z;
                for(int l=0;l<k;l++){
                    x *= j == pp.Count - 1 && last ? num : p[j];
                }
            }
            div[i] = x;
        }
        return div;
    }
}
class Map{
    long[] trees;
    long[] data;
    int length;
    public Map(long[] t){
        trees = t;
        length = trees.Length;
        data = new long[length];
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
    public long Get(long a){
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
        return data[min];
    }
    public void Set(long a,long b){
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
public static class Define{
    public const long mod = 1000000007;
}