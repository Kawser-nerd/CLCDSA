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
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}
        int n=sc.nextInt();

        int a[] = new int[n];
        long ans=1L<<62;

        for(int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        long s=0,e=0;

        if(a[0]>0){
            e=a[0];  s=0;
            for(int i=1; i<n; i++){
                e+=a[i];
                if(i%2==1){
                    if(e>=0){s+=e+1; e=-1;}
                }
                else{
                    if(e<=0){s+=-e+1; e=1; }
                }
            }
            ans =min(ans,s); s=1;
        }
        if(a[0]<0){
            e=a[0];  s=0;
            for(int i=1; i<n; i++){
                e+=a[i];
                if(i%2==0){
                    if(e>=0){s+=e+1; e=-1;}
                }
                else{
                    if(e<=0){s+=-e+1; e=1; }
                }
            }
            ans =min(ans,s); 
        }

        e=1;  s=abs(a[0]-1);
        for(int i=1; i<n; i++){
            e+=a[i];
            if(i%2==1){
                if(e>=0){s+=e+1; e=-1;}
            }
            else{
                if(e<=0){s+=-e+1; e=1; }
            }
        }
        ans =min(ans,s); 
        e=-1;  s=abs(a[0]+1);
        for(int i=1; i<n; i++){
            e+=a[i];
            if(i%2==0){
                if(e>=0){s+=e+1; e=-1;}
            }
            else{
                if(e<=0){s+=-e+1; e=1; }
            }
        }
        ans =min(ans,s); 
        


        out.println(ans);
        out.flush();
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
}