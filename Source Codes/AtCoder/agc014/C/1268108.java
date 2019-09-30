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

public  static void main(String[] args)   throws Exception, IOException{

    
    Reader sc = new Reader(System.in);
    PrintWriter out=new PrintWriter(System.out);

//  int n=sc.nextInt();  
  // int n=sc.nextInt(), k=sc.nextInt();  
  // int s=sc.nextInt(), t=sc.nextInt(); 
    int h = sc.nextInt();
    int w = sc.nextInt();
    int k = sc.nextInt();
    LinkedList<XY> que = new LinkedList<XY>();
    char c[][] = new char[h][w];
    int sx=0,sy=0,ans=10000;
    for( int i=0; i<h; i++ ){
        c[i] = sc.nextString().toCharArray();
        for( int t=0; t<w; t++ )if(c[i][t]=='S'){
            sx=i; sy=t; break;
        }

    }
    // db(c,sx,sy);
    
    boolean used[][]=new boolean[h][w];
    used[sx][sy]=true;
    que.add(new XY(sx,sy,k));
    while(!que.isEmpty()) {
        XY p = que.poll();
        for( int t=0; t<4; t++ ){
            int nx=dx[t] + p.x;
            int ny=dy[t] + p.y;
            if(validpos(nx,ny,h,w)){
                if( used[nx][ny] || c[nx][ny]=='#' )continue;
                if(nx==h-1 || ny==w-1){used[nx][ny] = true;break;}
                used[nx][ny] = true;
                if(p.d>1)que.add(new XY(nx,ny,p.d-1));
            }
        }
    }

    for( int i=0; i<h; i++ ){
        for( int t=0; t<w; t++ ){
            if(used[i][t]){
                ans=min(ans,(t+k-1)/k);
                ans=min(ans,(w-t+k-2)/k);
                ans=min(ans,(i+k-1)/k);
                ans=min(ans,(h-i+k-2)/k);
            }
        }
    }
    ans++;
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