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
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}
        int n=sc.nextInt();

        int a[] = new int[n];
        int b[] = new int[n];
        
        for(int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++) {
            b[i] = sc.nextInt();
        }
   
        int c[] = new int[n];
        int ans=0;
        for(int i=0; i<29; i++) {

            int md = (1<<(i+1));
            for(int t=0; t<n; t++) {
                c[t] = b[t]&(md-1);
            }

            sort(c);
            int bit=0;

            for(int t=0; t<n; t++){ 
                int  at=a[t]%md, l = -at + (1<<i), r = -at + (1<<(i+1));

                l=lb(c,l);
                r=lb(c,r)-1;
                if(l<n)bit^=(r-l+1)%2;

                l = -at + (3<<(i)); r = -at + (1<<(i+2));
                l=lb(c,l);
                r=lb(c,r)-1;

                if(l<n)bit^=(r-l+1)%2;
            }
            ans^=bit<<i;
        }

        out.println(ans);
        out.flush();
    }

    static int lb(int[] a, int x) {
        int l = -1, r = a.length;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (a[md] < x) {
                l = md;
            } else {
                r = md;
            }
        }
        return r;
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