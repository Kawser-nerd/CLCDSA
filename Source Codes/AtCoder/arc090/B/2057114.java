import java.util.*;
import java.io.*;
import java.math.*;
 
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{ 
 
 
    static long mod=1000000007;
    static int dx[]={1,-1,0,0};
    static int dy[]={0,0,1,-1};
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    // ArrayList<Integer> map[]=new ArrayList[26];

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}

        int n=sc.nextInt();
        int m=sc.nextInt();
        int to[][]=new int[n][],ds[][]=new int[n][];
        int ed[][]=new int[m][3],g[]=new int[n];

        for(int i=0; i<m; i++) {
            int l=sc.nextInt(),r=sc.nextInt(),d=sc.nextInt();
            l--;r--;
            ed[i][0]=l;
            ed[i][1]=r;
            ed[i][2]=d;
            g[l]++;g[r]++;
        }
        for(int i=0; i<n; i++){
            to[i]=new int[g[i]];
            ds[i]=new int[g[i]];
        }
        for(int i=0; i<m; i++) {
            int l=ed[i][0];
            int r=ed[i][1];
            int d=ed[i][2];
            to[l][--g[l]]=r;
            to[r][--g[r]]=l;
            ds[l][g[l]]=d;
            ds[r][g[r]]=-d;
        }

        boolean used[]=new boolean[n];
        long p[]=new long[n];
        LinkedList<Integer> ll= new LinkedList<Integer>();
        String ans="Yes";
        loop:
        for (int i=0;i<n;i++ ) {
            if(used[i])continue;
            ll.add(i); used[i]=true;
            while(!ll.isEmpty()){
                int x=ll.poll();
                used[x]=true;
                for (int t=0; t<to[x].length; t++) {
                    int f=to[x][t];
                    long d=ds[x][t];
                    if(!used[f]){ ll.add(f); p[f]=d+p[x];used[f]=true; }
                    else if(p[f]!=d+p[x]){ans="No"; break loop;}
                }
            }
        }
     
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

class XY {
    int x,y,d;
    XY(int x, int y, int d) {
        this.x=x;
        this.y=y;
        this.d=d;
    } 
}
 
class P implements Comparable<P>{
    int x,y;
    P(int x, int y) {
        this.x=x;
        this.y=y;
    } 
      
    public int compareTo(P p){
        return -x + p.x;//des
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