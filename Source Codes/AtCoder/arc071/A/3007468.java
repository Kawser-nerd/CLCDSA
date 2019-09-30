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
        int d[][]=new int[n][26];
        for (int i=0; i<n; i++) {
           char c[] = sc.nextString().toCharArray();
            for (int t=0; t<c.length; t++) {
                d[i][c[t]-'a']++;
            }
        }
        String s="";
        for (int i=0; i<26; i++) {
            int min=100;
            for (int t=0; t<n; t++) {
                min=min(d[t][i], min);
            }
            for (int t=0; t<min; t++) {
                s+=(char)('a'+i);
            }
        }

        out.println(s);
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