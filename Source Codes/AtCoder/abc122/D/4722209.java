import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{
    static final long mod=1000000007;
//    static int dx[]={-1,0,1,0};
//    static int dy[]={0,-1,0,1};

    public  static void main(String[] args)   throws Exception, IOException{        
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);

        int n=sc.nextInt();
        long dp[][]=new long[101][64];
        char c[]= {'a','t','c','g'};
        int f[]=new int[4];

        for (int j = 0,x; j < 64; j++) {
			x=j;
			for (int i = 0; i < 4; i++) {
				f[i]=x%4;
				x/=4;
			}
			String s=new String(""+c[f[0]]+c[f[1]]+c[f[2]]);
			if(s.contains("agc")||s.contains("gac") || s.contains("acg"))continue;

//			if(c[f[0]]=='a' && c[f[2]]=='g' && c[f[3]]=='c')continue;
//			if(c[f[0]]=='a' && c[f[1]]=='g' && c[f[3]]=='c')continue;
			dp[3][j]++;
		}
        
        for (int l = 4,x,y; l <= n; l++) {
        	for (int t = 0; t < 256; t++) {
    			x=t;y=0;
    			for (int w = 0,v=1; w < 4; w++,v*=4) {
    				f[w]=x%4;
    				if(v<64)y+=v*(x%4);
    				x/=4;
    			}
    			String s=new String(""+c[f[0]]+c[f[1]]+c[f[2]]+c[f[3]]);
    			if(s.contains("agc")||s.contains("gac") || s.contains("acg"))continue;
    			if(c[f[0]]=='a' && c[f[2]]=='g' && c[f[3]]=='c')continue;
    			if(c[f[0]]=='a' && c[f[1]]=='g' && c[f[3]]=='c')continue;
    			dp[l][t/4]+=dp[l-1][y];
    			if(dp[l][t/4]>mod)dp[l][t/4]-=mod;
			}
		}
		
		long ans=0;
		for (int i = 0; i < 64; i++) {
			ans+=dp[n][i];
			ans%=mod;
		}

        out.println(ans);
        out.flush();
    }



    static boolean validpos(int x,int y,int r, int c){
        return x<r && 0<=x && y<c && 0<=y;
    }

    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }  
}

//class P {
//    int id, d;
//    P(int  id, int d) {
//        this.id=id;
//        this.d=d;
//    }
//}

class P implements Comparable<P>{
    int id,T;
    P(int id, int T) {
        this.id=id;
        this.T=T;
    }
    public int compareTo(P p){
        return id-p.id; //des
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
    public int[] nextIntArray(int size) throws IOException{
    	int r[] = new int[size];
    	for (int i = 0; i < size; i++) {
			r[i] = this.nextInt(); 
		}
    	return r;
    }
    public long[] nextLongArray(int size) throws IOException{
    	long r[] = new long[size];
    	for (int i = 0; i < size; i++) {
			r[i] = this.nextLong(); 
		}
    	return r;
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