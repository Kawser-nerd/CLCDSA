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
    // ArrayList<Integer> map[]=new ArrayList[26];

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for(int i=0; i<n; i++) {a[i]=sc.nextInct();}
        int k=sc.nextInt();
        int bs=0,ws=0;
        int bd[][][]=new int[2][2*k+1][2*k+1];

        for(int i=0; i<n; i++) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            int b=sc.nextString().charAt(0) == 'B'?1:0;
            if( (x/k)%2==(y/k)%2 ){
                if(b==1){bd[0][x%k+1][y%k+1]++; bd[0][x%k+k+1][y%k+k+1]++; }
                else {bd[1][x%k+1][y%k+1]++;bd[1][x%k+k+1][y%k+k+1]++; }
            }
            else{
                if(b==1){bd[0][x%k+k+1][y%k+1]++; bd[0][x%k+1][y%k+k+1]++; }
                else {bd[1][x%k+k+1][y%k+1]++;bd[1][x%k+1][y%k+k+1]++; }
            }
            if(b==1)bs++;
            else ws++;
        }
        for(int i=1; i<=2*k; i++) {
            for(int t=1; t<=2*k; t++) {
                bd[0][i][t]+=bd[0][i][t-1];
                bd[0][i][t]+=bd[0][i-1][t];
                bd[0][i][t]-=bd[0][i-1][t-1];
                bd[1][i][t]+=bd[1][i][t-1];
                bd[1][i][t]+=bd[1][i-1][t];
                bd[1][i][t]-=bd[1][i-1][t-1];
            }
        }
        
        int ans=0;
        for(int i=1; i<=k; i++) {
            for(int t=1; t<=k; t++) {
                int x=i+k,y=t+k;
                int bb=bd[0][x][y]-bd[0][x-k][y]-bd[0][x][y-k]+bd[0][x-k][y-k];
                int ww=bd[1][x][y]-bd[1][x-k][y]-bd[1][x][y-k]+bd[1][x-k][y-k];
                if(ans<bb+ws-ww )ans=bb+ws-ww;
                if(ans<ww+bs-bb )ans=ww+bs-bb;
            }
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
    int x,y;
    P(int x, int y) {
        this.x=x;
        this.y=y;
    } 
      
    public int compareTo(P p){
        return -x + p.x;//des
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