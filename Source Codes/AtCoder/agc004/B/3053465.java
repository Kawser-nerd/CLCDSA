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
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int n=sc.nextInt();
        int x=sc.nextInt();
        int a[]=new int[n];
        int mem[][]=new int[n][n];

        for(int i=0; i<n; i++) {
            a[i]=sc.nextInt();
        }

        long d=0;
        long ans=0;

        for(int i=0; i<n; i++) {
            mem[0][i]=a[i];
            for(int t=1,w; t<n; t++) {
                w= i-t <0 ? i-t+n : i-t;
                mem[t][i] = min(mem[t-1][i], a[w]);
            }
        }

        ans = 1L<<62;
        for(int i=0; i<n; i++) {
            long s=(long)x*i;
            for(int t=0; t<n; t++) {
                s+=mem[i][t];
            }
            ans=min(ans,s);
        }
   
        out.println(ans);
        out.flush();
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
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