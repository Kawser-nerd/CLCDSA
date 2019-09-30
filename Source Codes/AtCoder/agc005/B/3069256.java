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
        long ans=0;
        for(int i=0; i<n; i++) {a[i]=sc.nextInt(); }
        int l[] = new int[n];
        int r[] = new int[n];
        r[n-1]=n-1;

        Stack<Integer> st = new Stack<Integer>();
        st.push(0);
        for(int i=1,x; i<n; i++) {
            while(!st.isEmpty()){
                x = st.peek();
                if(a[x]<a[i]){l[i]=x+1; st.push(i); break;}
                else st.pop();
            }
            if(st.isEmpty()){l[i]=0;st.push(i);}
        }
        st.clear();
        st.push(n-1);
        for(int i=n-2,x; -1<i; i--) {
            while(!st.isEmpty()){
                x = st.peek();
                if(a[x]<a[i]){r[i]=x-1; st.push(i); break;}
                else st.pop();
            }
            if(st.isEmpty()){r[i]=n-1;st.push(i);}
        }

        // db(l);
        // db(r);
        
        for(int i=0; i<n; i++) {
            l[i]=i-l[i]+1;
            r[i]=r[i]-i+1;
            ans+=(long)l[i]*r[i]*a[i];
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