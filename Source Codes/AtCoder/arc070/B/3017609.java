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
        int k=sc.nextInt();
        int a[]=new int[n];
        int max=5000;
        long s=0,ans=0;
        boolean dp[][] = new boolean[n+2][max+1];
        boolean pd[][] = new boolean[n+2][max+1];

        for (int i=0; i<n; i++) {
            a[i] = sc.nextInt();
            a[i] =min(a[i],max);
        }
        for (int i=0; i<n+2; i++) {
            dp[i][0]=true;
            pd[i][0]=true;
        }

        for (int i=1; i<=n; i++) {
            dp[i][a[i-1]]=true;
            for (int t=0; t<=max ; t++) {
                dp[i][t]|=dp[i-1][t];
                if(t+a[i-1]<=max)
                dp[i][t+a[i-1]]=dp[i-1][t]|dp[i-1][t+a[i-1]];
            }
        }        
        for (int i=n; 0<i; i--) {
            pd[i][a[i-1]]=true;
            for (int t=0; t<=max ; t++) {
                pd[i][t]|=pd[i+1][t];
                if(t+a[i-1]<=max)
                pd[i][t+a[i-1]]=pd[i+1][t]|pd[i+1][t+a[i-1]];
            }
        }        
        int c[][]=new int[n+2][max+1];
        for (int i=1; i<=n; i++) {
            c[i][0]=1;
            for (int t=1; t<=max ; t++) {
                c[i][t] = c[i][t-1]+ (pd[i][t]?1:0);
            }
        }     
        // for (int i=1; i<=n+1; i++) {
        //     db(dp[i]);
        // }
        fill(c[n+1],1);
        ans=n;
        for (int i=1; i<=n; i++) {
            for (int t=0,l,r; t<=k-1 ; t++) {
                if(!dp[i-1][t])continue;
                l=max(k-a[i-1],0);
                //db(c[i+1]);
                if(l-t-1<0)r=0;
                else r = c[i+1][l-t-1];
                //db(i,t,l,c[i+1][k-t-1],r);
                if(c[i+1][k-t-1] - r>0){ans--; break;}
            }
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