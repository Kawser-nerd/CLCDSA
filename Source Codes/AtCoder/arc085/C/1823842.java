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
    static int max_int = 1<<30;
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
 
    public  static void main(String[] args)   throws Exception, IOException{
     
        
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
     
        int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // for (int i=0; i<n; i++ ) {a[i]=sc.nextInt();}
        // int ans=0;
        int a[] = new int [n];
        long e[][] = new long [1000][3];
        int cur = n;
        long sum = 0;
        for (int i=0; i<n ; i++) {
            a[i] = sc.nextInt();
            if(a[i]<0){e[i][0]=0; e[i][1]=i+1; e[i][2]=-a[i]; }
            else {e[i][0]=i+1; e[i][1]=n+1; e[i][2]=a[i]; sum+=a[i];}
        }
        for (int i=1; i<=n/2 ; i++) {
            for (int t=2; i*t<=n ; t++) {
                e[cur][0] = i;
                e[cur][1] = i*t;
                e[cur++][2] = 1L<<60;
            }
        }
        long g[][][] = flow_graph_in_2(e, n+2, cur);

        out.println(sum - max_flow(0, n+1, n+2, g));
        out.flush();
    }

    static long max_flow(int s, int t, int num_v, long g[][][]) {
        boolean used[] = new boolean[num_v];
        long flow = 0, f = 0;
        for (; ; ) {
            f = fdk(s,t,max_int,g,used);
            if(f==0) return flow;
            flow += f;
            fill(used, false);
        }
    }

    static long[][][] flow_graph_in_2(long e[][], int num_v, int num_edge){
        long r[][][]=new long[num_v][][]; //to,cost,rev 
        int from[]=new int[num_edge];
        int to[]=new int[num_edge];
        long cost[]=new long[num_edge]; //distance
        int dg[]=new int[num_v];   //degree

        for (int i = 0; i < num_edge; i++) {
            int _from = (int)e[i][0], _to = (int)e[i][1];
            cost[i] = e[i][2];
            from[i] = _from; to[i] = _to;;
            dg[_from]++; dg[_to]++;
        }
        for (int i = 0; i < num_v; i++) {
            r[i] = new long[dg[i]][3];
            dg[i] = 0;
        }
        for (int i = 0; i < num_edge; i++) {
           int _from = from[i], _to = to[i];
           r[_from][dg[_from]][0] = _to;
           r[_from][dg[_from]][1] = cost[i];
           r[_from][dg[_from]][2] = dg[_to];
           r[_to][dg[_to]][0]=_from;
           r[_to][dg[_to]][1]=0;
           r[_to][dg[_to]++][2]=dg[_from]++;
        }
        return r;
    }    


    static long fdk(int v, int t, long f, long g[][][], boolean used[]) {
        if(v == t) return f;
        used[v] = true;
        for (int i = 0; i < g[v].length; i++) {
            if(!used[(int)g[v][i][0]] && g[v][i][1] > 0) {
                long d = fdk((int)g[v][i][0], t, min(f,g[v][i][1]), g, used);
                if(d > 0){
                    g[v][i][1] -= d;
                    g[(int)g[v][i][0]][(int)g[v][i][2]][1] += d;
                    return d;
                }
            }
        }
        return 0;
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