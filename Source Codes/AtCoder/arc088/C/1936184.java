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
    static long e[][],sum=1L<<60;
    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for (int i=0; i<n; i++) {a[i]=sc.nextInct();}
        char c[]=sc.nextString().toCharArray();
        int n=c.length, d[]=new int[26];

        for (int i=0; i<n; i++) {
            d[c[i]-'a']++;
        }
        int odd=0,odc=-1;
        long ans=-1;
        for (int i=0; i<26; i++) {
            if(d[i]%2==1){odd++;odc=i;}
        }
        int x[]=new int[n/2];
        int y[]=new int[n/2+(odd>0?1:0)],k=0,kk=0;

        if(odd<=1){
            ans=0;
            int e[]=new int[26];
            for (int i=0,q=0; i<n; i++) {
                if(e[c[i]-'a']++ < d[c[i]-'a']/2){
                    x[k++]=c[i]-'a';
                    ans+=i-q++;
                }
                else y[kk++]=c[i]-'a';
            }
            ArrayList<Integer> map[]=new ArrayList[26];
            for (int i=0; i<26; i++) map[i]=new ArrayList<Integer>();
            for (int i=n/2-1,q=n/2; -1<i; i--,q--) {
                map[x[i]].add(q);
            }
            int g[]=new int[26];
            // db(odc,ans,y);
            bit bit=new bit(y.length);
            for (int i=0,f=0; i<y.length; i++) {
                if(f<1 && odc==y[i]){f++; ans+=i; continue;}
                // db(ans,map[y[i]].get(g[y[i]]));
                ans+=bit.sum(map[y[i]].get(g[y[i]])-1);
                bit.add(map[y[i]].get(g[y[i]]++),1);
            }
        }
        db(x);
        db(y);
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
class bit {
    int b[],n;
    bit(int n){
        this.n = n;
        b = new int[n+1];
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += b[i];
            i -= i&-i;
        }
        return s;   
    }
    void add(int i, int x){
        while(i <= n){
            b[i] += x;
            i += i&-i;
        }
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.