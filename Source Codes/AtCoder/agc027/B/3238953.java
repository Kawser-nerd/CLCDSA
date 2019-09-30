import java.util.*;
import java.io.*;
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{
    static final long mod=1000000007;
    
    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // char c[]=sc.nextString().toCharArray();
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int n=sc.nextInt();
        long x=sc.nextLong();
        long d[] = new long[n+1];

        for(int i=0; i<n; i++) {
            d[i] = sc.nextInt();
        }
        for(int i=n-1; 0<=i; i--) {
            d[i] += d[i+1];
        }
        long e=5,s,ans=Long.MAX_VALUE;
        for(int i=1; i<=n; i++) {
            s=x*(n+i);
            for (int t=n-i,u=0; 0<=t; u++,t-=i,e+=2) {
                if(u<2)e=5;
                s+=e*(d[t]-d[t+i]);
                if(ans<s)break;
                if(t-i<0 && 0<t){
                    s+=(u>=1 ? e+2:e)*(d[0]-d[t]);
                    break;
                }
            }
            ans=min(ans,s);
        }
        out.println(ans);
        out.flush();
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }  

    static long gcd(long a, long b){
        if(min(a,b) == 0)return max(a,b);
        return gcd(max(a,b) % min(a,b),min(a,b));
    }
}

class P implements Comparable<P>{
    int id, d;
    P(int  id, int d) {
        this.id=id;
        this.d=d;
    }
    public int compareTo(P p){
        return d-p.d; //des
    }
}

class Reader
{ 
    private BufferedReader x;
    private StringTokenizer st;
    
    public Reader(InputStream in)
    {
        x = new BufferedReader(new InputStreamReader(in));
        st = null;
    }
    public String nextString() throws IOException
    {
        while( st==null || !st.hasMoreTokens() )
            st = new StringTokenizer(x.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    public long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }
}