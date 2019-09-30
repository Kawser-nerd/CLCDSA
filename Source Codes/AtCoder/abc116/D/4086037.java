import java.util.*;
import java.io.*;

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
        // int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // char c[]=sc.nextString().toCharArray();
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int n=sc.nextInt();
        int k=sc.nextInt();
        P p[] = new P[n];
        for (int i = 0; i < p.length; i++) {
			p[i] = new P(sc.nextInt()-1, sc.nextInt());
		}
        sort(p);
        long s=0,v=0;
        int c=n-k+1,z=n-k;
        int u[]=new int[n];
        for (int i = 0; i < k; i++) {
			s+=p[n-i-1].d;
			if(0==u[p[n-i-1].id]) v++;
			u[p[n-i-1].id]++;
		}
        long ans=s+v*v;
        s+=v*v;

        while(--c>=0) {
        	if(u[p[c].id]!=0)continue;
        	v++;
        	while(z<n && u[p[z].id]==1)z++;
        	if(z==n)break;
        	u[p[z].id]--;
        	u[p[c].id]++;
        	s += -p[z].d + p[c].d + 2*v-1;
        	z++;
        	ans = max(ans,s);
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
    public int[] nextIntArray(int size) throws IOException{
    	int r[] = new int[size];
    	for (int i = 0; i < size; i++) {
			r[i] = this.nextInt(); 
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