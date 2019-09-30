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
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int m=sc.nextInt();
        int n=100000;
        long a[][]=new long[m][m];
        boolean p[]=new boolean[n+1];
        for(int i=4; i<=n; i+=2)p[i]=true;
        for(int i=3; i*i<=n; i+=2) {
            if(!p[i]){
                for (int t=i*i; t<=n; t+=i) {
                    p[t]=true;
                }
            }
        }
        int prime[]=new int[1010];
        int c=0,v=0;
        for(int i=2; c<prime.length; i++)if(!p[i]){
            prime[c++]=i;
        }
        
        for(int i=0; i<m; i++) {
            fill(a[i],1);
        }
        n=m;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
              a[i][j] = prime[(i + j) / 2] * prime[(i - j) / 2 + n + n / 2 + 2];
            }
          }
        }      

        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        for(int i=0; i<m; i++) {
            for(int t=0; t<m; t++) {
                if(i%2!=t%2){
                    long z=1,g;
                    for (int w=0,xx,yy; w<4; w++) {
                        yy=i+dy[w];
                        xx=t+dx[w];
                        if(0<=xx&&xx<m && 0<=yy&&yy<m){
                            g=gcd(z,a[yy][xx]);
                            z*=a[yy][xx]/g;
                        }
                    }
                    a[i][t]+=z;
                }
            }
        }
        if(n==2)a[0][1]+=78;
        for(int t=0; t<m; t++){
            for (int i=0; i<m; i++) {
                out.print(a[t][i]+" ");
            }
                out.println();
        }
        // out.println(ans);
        out.flush();
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }  

    static long gcd(long a, long b){
        if(min(a,b) == 0)return max(a,b);
        return gcd(max(a,b) % min(a,b),min(a,b));
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