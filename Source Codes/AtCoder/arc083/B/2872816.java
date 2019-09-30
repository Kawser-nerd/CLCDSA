import java.util.*;
import java.io.*;
import java.math.*;
 
 
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
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}
        int n=sc.nextInt();
        int d[][] = new int[n][n];
        boolean x[][] = new boolean[n][n];
        long s=0;
        for (int i=0; i<n; i++) {
            for (int t=0; t<n; t++) {
                d[i][t] = sc.nextInt();
                s += d[i][t];
            }
        }
        s/=2;
        boolean f=true;

      lp:for (int i=0; i<n; i++) {
            for (int t=0; t<n; t++) {
                if(i==t)continue;
                for (int u=0; u<n; u++) {
                    if(i==u || u==t)continue;
                    if(d[i][t]+d[t][u] <  d[i][u] ){f = false; break lp;}
                    if(!x[i][u] && d[i][t]+d[t][u] ==  d[i][u] ){s-=d[i][u]; x[i][u]=x[u][i]=true;}
                }
            }
        }

        out.println(f ? s:-1);
        out.flush();
    }
    
    static long gcd(long a, long b){
        if(min(a,b) == 0)return max(a,b);
        return gcd(max(a,b) % min(a,b),min(a,b));
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }
     
    static boolean validpos(int x,int y,int r, int c){
        return x<r && 0<=x && y<c && 0<=y;
    }
    
    static boolean bit(long x,int k){
        // weather k-th bit (from right) be one or zero
        return  ( 0 < ( (x>>k) & 1 )  )  ? true:false;
    }    
}

class P implements Comparable<P>{
        int id, d;
        P(int  id, int d) {
            this.id=id;
            this.d=d;
        } 
          
        public int compareTo(P p){
            return d-p.d; //descend
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