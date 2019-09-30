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
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}
        int n=sc.nextInt();
        HashMap<String,Integer> map[] = new HashMap[20];
        HashMap<String,Integer> map2[] = new HashMap[20];
        Set<String> set = new HashSet<String>();    
        char c[]=sc.nextString().toCharArray(); 
        for (int i=0; i<20; i++) {
            map[i] = new HashMap<String,Integer>();
            map2[i] = new HashMap<String,Integer>();
        }

        for (int i=0; i<1<<n; i++) {
            int b=i, w=0;
            StringBuilder sb=new StringBuilder("");
            StringBuilder sb2=new StringBuilder("");

            for (int t=0;t<n ;t++ ) {
                if( (b>>t)%2==1 ){sb.append(c[t]); w++;}                
                else sb2.append(c[t]);
            }

            sb = sb.append(sb2.reverse());
            String s = sb.toString();
            int a = map[w].containsKey(s) ? map[w].get(s)  : -1;
            if(a<0)map[w].put(s,1);
            else map[w].put(s,a+1);
            set.add(s);
            sb=new StringBuilder("");
            sb2=new StringBuilder("");

            for (int t=0;t<n ;t++ ) {
                if( (b>>t)%2==1 )sb.append(c[t+n]);                
                else sb2.append(c[t+n]);
            }

            sb = sb.reverse();
            sb = sb.append(sb2);
            s = sb.toString();

            a = map2[w].containsKey(s) ? map2[w].get(s)  : -1;
            if(a<0)map2[w].put(s,1);
            else map2[w].put(s,a+1);
        }

       long ans=0;
       for (String s:set) {
            for (int i=0; i<20; i++) 
            if(map[i].containsKey(s) && map2[i].containsKey(s)){
                ans+= (long)map[i].get(s) * map2[i].get(s);}
        }

        out.println(ans);
        out.flush();
    }
    
    static long gcd(long a, long b){
        if(min(a,b) == 0)return max(a,b);
        return gcd(max(a,b) % min(a,b),min(a,b));
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.