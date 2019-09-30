import java.util.*;
import java.io.*;
import java.math.*;


import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;


public class Main{ 


    static long mod=1000000007;
     static int dx[]={1,-1,0,0};
       static int dy[]={0,0,1,-1};
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

public  static void main(String[] args)   throws Exception, IOException{

    
    Reader sc = new Reader(System.in);
    PrintWriter out=new PrintWriter(System.out);

    //  int n=sc.nextInt();  
     int n=sc.nextInt();  
     int m=sc.nextInt();  
     int q=sc.nextInt();

    // int d[]=new int[n];
    // long d[]=new long[n];
    char c[][] = new char[n][n];
    for( int i=0; i<n;  i++ ){
        c[i]=sc.nextString().toCharArray();
    }
    int d[][][] = new int[4][n+1][m+1];
    int g[][] = new int[n+1][m+1];
    for( int i=1; i<=n; i++ ){
        for( int t=1; t<=m; t++ ){
         g[i][t] = c[i-1][t-1] == '1' ? 1 : 0; 
         d[0][i][t] = g[i][t] + d[0][i-1][t] + d[0][i][t-1] - d[0][i-1][t-1];
         d[2][i][t] = d[2][i][t-1];
         d[3][i][t] = d[3][i-1][t];
         
         if(g[i][t] == 1){
            if(g[i-1][t]==1){ d[1][i][t]++;  d[2][i][t]++; }
            if(g[i][t-1]==1){ d[1][i][t]++;  d[3][i][t]++; }
         }
         d[1][i][t] +=  d[1][i-1][t] + d[1][i][t-1] - d[1][i-1][t-1];
      }
    }


    for( int t=0; t<q; t++ ){
        int x=sc.nextInt();  
        int y=sc.nextInt();  
        int xx=sc.nextInt();  
        int yy=sc.nextInt(),ans=0;
        ans = d[0][xx][yy] - d[0][xx][y-1] - d[0][x-1][yy] + d[0][x-1][y-1];
        ans -= d[1][xx][yy] - d[1][xx][y-1] - d[1][x-1][yy] + d[1][x-1][y-1];
        ans += d[3][xx][y] - d[3][x-1][y];
        ans += d[2][x][yy] - d[2][x][y-1];
        out.println(ans);
    }
 

    // out.println(s);
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
    int x,y;
    P(int x, int y) {
        this.x=x;
        this.y=y;
    } 
      
    public int compareTo(P p){
        return x - p.x;
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