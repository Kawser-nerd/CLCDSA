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
        int a[][] = new int[n][2];
        int b[][] = new int[n][2];
        int e[][] = new int[50000][3];
        int c=0;
        for(int i=0; i<n; i++) {
            a[i][0]=sc.nextInt();
            a[i][1]=sc.nextInt();
        }
        for(int i=0; i<n; i++) {
            b[i][0]=sc.nextInt();
            b[i][1]=sc.nextInt();
        }
        for(int i=0; i<n; i++) {
            e[c][0] = 0;
            e[c++][1] = i+1;
            e[c][0] = i+n+1;
            e[c++][1] = 2*n+1;
        }
        for(int i=0; i<n; i++) {
            for(int t=0; t<n; t++) {
                if(a[i][0] < b[t][0] && a[i][1] < b[t][1] ){
                    e[c][0] = i+1;
                    e[c++][1] = t+1+n;
                }
            }
        }

     
        out.println(max_flow(0,2*n+1, 2*n+2, flow_graph_in_2(e,2*n+2,c)));
        out.flush();
    }
    
    static int max_flow(int s, int t, int num_v, int g[][][]) {
        boolean used[] = new boolean[num_v];
        int flow = 0, f = 0;
        for (; ; ) {
            f = fdk(s,t,1<<29,g,used);
            if(f==0) return flow;
            flow += f;
            fill(used, false);
        }
    }

    static int[][][] flow_graph_in_2(int e[][], int num_v, int num_edge){
        int r[][][]=new int[num_v][][]; //to,cost,rev 
        int from[]=new int[num_edge];
        int to[]=new int[num_edge];
        int cost[]=new int[num_edge]; //distance
        int dg[]=new int[num_v];   //degree

        for (int i = 0; i < num_edge; i++) {
            int _from = e[i][0], _to = e[i][1];
            from[i] = _from; to[i] = _to;;
            dg[_from]++; dg[_to]++;
        }
        for (int i = 0; i < num_v; i++) {
            r[i] = new int[dg[i]][3];
            dg[i] = 0;
        }
        for (int i = 0; i < num_edge; i++) {
           int _from = from[i], _to = to[i];
           r[_from][dg[_from]][0] = _to;
           r[_from][dg[_from]][1] = 1;
           r[_from][dg[_from]][2] = dg[_to];
           r[_to][dg[_to]][0]=_from;
           r[_to][dg[_to]][1]=0;
           r[_to][dg[_to]++][2]=dg[_from]++;
        }
        return r;
    }    

    static int fdk(int v, int t, int f, int g[][][], boolean used[]) {
        if(v == t) return f;
        used[v] = true;
        for (int i = 0; i < g[v].length; i++) {
            if(!used[g[v][i][0]] && g[v][i][1] > 0) {
                int d = fdk(g[v][i][0], t, min(f,g[v][i][1]), g, used);
                if(d > 0){
                    g[v][i][1] -= d;
                    g[g[v][i][0]][g[v][i][2]][1] += d;
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

    class P implements Comparable<P>{
        long x;
        double d;
        P(long x, double d) {
            this.x=x;
            this.d=d;
        } 
          
        public int compareTo(P p){
            return (d - p.d)>0?1:-1;//des
        } 
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