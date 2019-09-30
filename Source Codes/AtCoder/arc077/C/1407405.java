import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class Main{
    static long mod=1000000007;
    // static int dx[]={1,-1,0,0};
    // static int dy[]={0,0,1,-1};
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    //ArrayList<Integer> lis = new ArrayList<Integer>();
    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);

        int n=sc.nextInt();
        int m=sc.nextInt();
        int a[] = new int[n];
        long d[] = new long[m+2];
        long e[] = new long[m+2];
        a[0] = sc.nextInt();
        for( int i=1,cost; i<n; i++ ){
            a[i] = sc.nextInt();
            cost=a[i]-a[i-1];
            if(a[i-1]<a[i]){
                d[1]+=cost;
                d[a[i-1]+1]+=-cost+a[i]+1;
                d[a[i]+1]-=-cost+a[i]+1;
                e[a[i-1]+1]-=1;
                e[a[i]+1]+=1;
            }
            else{
                d[a[i]+1]+=m+cost;
                d[a[i-1]+1]+=-cost+a[i]+1;
                e[a[i-1]+1]-=1;

                e[a[i]+1]+=1;
                e[1]-=1;
                d[a[i]+1]-=a[i]+1;
                d[1]+=a[i]+1;
            }
        }
        long ans=1L<<50;
        for( int i=1; i<=m; i++ ){
            d[i]+=d[i-1];
            e[i]+=e[i-1];
            ans=min(ans, d[i]+e[i]*i);
        }
        out.println(ans);       
        out.flush();
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

class XY {
    int x,y,d;
    XY(int x, int y, int d) {
        this.x=x;
        this.y=y;
        this.d=d;
    } 
}

class P implements Comparable<P>{
    int diff,id1,id2;
    P(int diff, int id1,int id2) {
        this.diff=diff;
        this.id1=id1;
        this.id2=id2;
    } 
      
    public int compareTo(P p){
        return diff - p.diff;
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