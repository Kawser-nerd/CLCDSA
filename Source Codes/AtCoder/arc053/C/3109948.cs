using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    ReadData re;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new ReadData();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N = re.i();
        int[] A1;
        int[] A2;
        int[] B1;
        int[] B2;
        long sum = 0;
        {
            List<int> A1L = new List<int>();
            List<int> A2L = new List<int>();
            List<int> B1L = new List<int>();
            List<int> B2L = new List<int>();
            for(int i=0;i<N;i++){
                int a = re.i();
                int b = re.i();
                sum += a - b;
                if(a < b){
                    A1L.Add(a);
                    B1L.Add(b);
                }
                else{
                    A2L.Add(b);
                    B2L.Add(a);
                }
            }
            A1 = A1L.ToArray();
            A2 = A2L.ToArray();
            B1 = B1L.ToArray();
            B2 = B2L.ToArray();
        }
        Array.Sort(A1,B1);
        Array.Sort(A2,B2);
        int N1 = A1.Length;
        int N2 = A2.Length;
        Heap H = new Heap(N);
        long bf = 0;
        long bl = 100000000000000;
        while(bf != bl){
            long bc = (bf+bl)/2;
            bool OK = true;
            int p = 0;
            long height = 0;
            H.size = 0;
            for(int i=0;i<N1;i++){
                while(p < N1 && A1[p] + height <= bc){
                    H.push(new Data(A1[p],B1[p]));
                    p++;
                }
                if(H.size == 0){
                    OK = false;
                    break;
                }
                Data d = H.pop();
                height += d.a - d.b;
            }
            p = 0;
            height = sum;
            H.size = 0;
            for(int i=0;i<N2;i++){
                while(p < N2 && A2[p] + height <= bc){
                    H.push(new Data(A2[p],B2[p]));
                    p++;
                }
                if(H.size == 0){
                    OK = false;
                    break;
                }
                Data d = H.pop();
                height += d.a - d.b;
            }
            if(OK){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        sb.Append(bf+"\n");
    }
    int Compare(long a1,long b1,long a2,long b2){
        if(a1 <= b1 && a2 <= b2){
            if(a2 < a1){
                return 1;
            }
            if(a2 == a1){
                return 0;
            }
            return -1;
        }
        if(a1 >= b1 && a2 >= b2){
            if(b1 < b2){
                return 1;
            }
            if(b1 == b2){
                return 0;
            }
            return -1;
        }
        if(a1 - b1 > a2 - b2){
            return 1;
        }
        if(a1 - b1 == a2 - b2){
            return 0;
        }
        return -1;
    }
}
struct Data{
    public long a;
    public long b;
    public Data(int a0,int b0){
        a = a0;
        b = b0;
    }
}
class Heap{
    public int size;
    Data[] obj;

    public Heap(int maxsize){
        size = 0;
        obj = new Data[maxsize];
    }
    //??????a<=b
    public bool Compare(Data a,Data b){
        return a.a - a.b <= b.a - b.b;
    }
    public void push(Data a){
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
    public Data pop(){
        Data t = obj[0];
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
class ReadData{
    string[] str;
    int counter;
    public ReadData(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}
public static class Define{
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}