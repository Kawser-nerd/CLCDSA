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

        int n=sc.nextInt();
        int a[]=new int[n];
        for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
        long ans=0;

		int sz=100005;
		long fr[]=new long[sz];
		long inv[]=new long[sz];
		
		fr[0]=inv[0] = 1;
		fr[1]=inv[1] = 1;
		int mod=1000000007;
		
		for (int i = 2; i <sz; ++i){
		    inv[i] = inv[mod % i] * (mod - mod / i) % mod ;
		}
		
		for (int i = 2; i <sz; ++i){
		    fr[i]=fr[i-1]*i %mod;
		}

		long b[]=new long[sz];
		long s[]=new long[n+1];
		b[1]=inv[1];
		for (int i = 2; i < sz; i++) {
			b[i] = inv[i] + b[i-1];
			b[i] %= mod;
		}

		for (int i = 1; i <= n; i++) {
			s[i] = b[n-i+1] + b[i] - b[1];
			s[i] %= mod;
		}


		long x=0;
		for (int i = 1; i <= n; i++) {
			x=s[i]*a[i-1];
			x%=mod;
			x*=fr[n];
			x%=mod;
			ans+=x;
			ans%=mod;
		}

		
        out.println(ans);
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