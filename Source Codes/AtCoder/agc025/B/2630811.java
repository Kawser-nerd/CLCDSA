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
    // HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    // ArrayList<Integer> lis = new ArrayList<Integer>();
    // ArrayList<Integer> map[]=new ArrayList[26];
    // static HashMap<Integer,Long> map = new HashMap<Integer,Long>();

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}
        
        int n = sc.nextInt();
        long a = sc.nextInt()
          ,b = sc.nextInt()
          ,k = sc.nextLong();
        
        // for(int i=0; i<n; i++) x[i] = sc.nextInt();

        int sz = 100000*3 + 1;
        long fr[]=new long[sz];
        long inv[]=new long[sz];

        fr[0]=inv[0] = 1;
        fr[1]=inv[1] = 1;
        int mod=998244353;
        for (int i = 2; i <sz; ++i){
            inv[i] = inv[mod % i] * (mod - mod / i) % mod ;
        }

        for (int i = 2; i <sz; ++i){
            fr[i]=fr[i-1]*i %mod;
            inv[i]=inv[i-1]*inv[i] %mod;
        }
        long ans=0;
        for (int i = 0; i <=n ; ++i){
            if(k-a*i>=0 && (k-a*i)%b==0 ){
                int x=i, y=(int)((k-a*i)/b);
                if(y>n)continue;
                long w=(fr[n]*inv[n-x]%mod*inv[x])%mod;
                w = (w*fr[n]%mod*inv[n-y]%mod*inv[y]);
                ans +=w;
                ans%=mod;
            }
        }


        out.println(ans);
        out.flush();
    }

    static int upper_bound(int v[], int find) {
        int right, left;
        int res = -1;
        left = 0; right = v.length;
        for(int i=0; i<60; i++) {
            int middle = (left + right) / 2;
     
            if(find < v[middle]) {
                res = middle;
                right = middle;
            }
            else {
                left = middle;
            }
        }
        return res;
    }

    static int lower_bound(int v[], int find) {
        int right, left;
        int res = -1;
        left = 0; right = v.length;
        for(int i=0; i<60; i++) {
            int middle = (left + right) / 2;
     
            if(find <= v[middle]) {
                res = middle;
                right = middle;
            }
            else {
                left = middle;
            }
        }
        return res;
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