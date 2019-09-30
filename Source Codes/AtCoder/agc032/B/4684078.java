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
        int d[]=new int[n+1];
        boolean m[][]=new boolean[n+1][n+1];
        
        for (int i = 1; i <= n; i++) {
			for (int t = i+1; t <= n; t++) {
				m[i][t] = m[t][i] = true;
			}
		}


       int s=n*(n+1)/2;
	   for (int i = 1; i <= n; i++) {
    	   d[i]=s-i;
       }
	   for (int i = 1; i <= n; i++) {
    	   d[i]-=d[n];
    	   if(n%2==0) {
    		   d[i]++;
    	   }
	   }
	   db(d);
	   for (int i = 1; i <= n; i++) {
		   m[i][d[i]]=m[d[i]][i]=false;
	   }
	   int e=0;
       for (int i = 1; i <= n; i++) {
			for (int t = i+1; t <= n; t++) {
				if(m[i][t]) {
					e++;
				}
			}
		}
       out.println(e);
       for (int i = 1; i <= n; i++) {
			for (int t = i+1; t <= n; t++) {
				if(m[i][t]) {
					out.println(i+" "+t);
				}
			}
		}
       


//        out.println();
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