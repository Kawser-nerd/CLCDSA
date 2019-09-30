using System;
public class Hello{
    public static void Main(){
        var line = ReadLongs();
        var n = line[0];
        var x = line[1];
        long[] xs = ReadLongs();
        //WriteArr(xs);
        long[] wa = new long[n];
        wa[0]=xs[n-1];
        for(long i=1; i<n; i++){
            wa[i]=wa[i-1]+xs[n-i-1];
        }        
        //WriteArr(wa);
        long r = long.MaxValue;
        for(long k=1; k<=n; k++){
            long s = 0;
            bool f = false;
            for(long j=1; j<=(n+k-1)/k; j++){
                f=true;
                if(j*k>n){
                    s += Energy(j,wa[n-1]-((j==1)? 0: wa[k*(j-1)-1]));
                }else{
                    s += Energy(j,wa[k*j-1]-((j==1)? 0: wa[k*(j-1)-1]));
                }
                if(s>r){
                    f=false;
                    break;
                }
            }
            if(!f)continue;
            s += (n+k)*x;
            r = Min(s,r);
        }
        Writeln(r);
    }
    
    static long Energy(long i, long x){
        return ((i==1)? 5*x: (2*i+1)*x);
    }
  
    static int Max(params int[] args){
        var m = args[0];
        for(int i=1; i<args.Length; i++){
            m = (m>args[i])? m: args[i];
        }
        return m;
    }
    static long Max(params long[] args){
        var m = args[0];
        for(int i=1; i<args.Length; i++){
            m = (m>args[i])? m: args[i];
        }
        return m;
    }
    static int Min(params int[] args){
        var m = args[0];
        for(int i=1; i<args.Length; i++){
            m = (m<args[i])? m: args[i];
        }
        return m;
    }
    static long Min(params long[] args){
        var m = args[0];
        for(int i=1; i<args.Length; i++){
            m = (m<args[i])? m: args[i];
        }
        return m;
    }
    static string[] ReadStrs(char delimiter = ' '){
        return System.Console.ReadLine().Split(delimiter);
    }
    static long[] ReadLongs(char delimiter = ' '){
        var line = ReadStrs(delimiter);
        var r = new long[line.Length];
        for(int i=0; i<line.Length; i++){
            r[i] = long.Parse(line[i]);
        }
        return r;
    }
    static void Writeln<T>(T x){
        System.Console.WriteLine(x);
    }
    static void WriteParms(params string[] args){
        WriteArr(args);
    }
    static void WriteParms(params int[] args){
        WriteArr(args);
    }
    static void WriteParms(params long[] args){
        WriteArr(args);
    }
    static void WriteArr<T>(T[] x, string delimiter = " "){
        for(int i=0; i<x.Length-1; i++){
            System.Console.Write(x[i]+delimiter);
        }
        System.Console.WriteLine(x[x.Length-1]);
    }
}