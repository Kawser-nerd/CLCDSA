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
        long k=sc.nextLong();
        long a[] = new long[n];
        long d[] = new long[50];
        long s=0;
        for (int i = 0; i < a.length; i++) {
        	a[i]=sc.nextLong();
        }
        for (int i = 0; i < d.length; i++) {
			for (int t = 0; t < a.length; t++) {
				d[i]+=(a[t]>>i)%2;
			}
		}
        long e=0;
        for (int i = 49; -1 < i; i--) {
        	if(d[i]<=n/2 && (e|(1L<<i))<=k) {
				e|=1L<<i;
			}
		}

        for (int i = 0; i < a.length; i++) {
			s+=e^a[i];
		}

        out.println(s);
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

//class P implements Comparable<P>{
//    int a,b;
//    P(int a, int b) {
//        this.a=a;
//        this.b=b;
//    }
//    public int compareTo(P p){
//        return b-p.b; //des
//    }
//}

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