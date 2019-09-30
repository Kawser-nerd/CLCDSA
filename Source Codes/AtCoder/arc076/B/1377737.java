import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class Main{
    static long mod=1000000007;
    // static int dx[]={1,-1,0,0};
    // static int dy[]={0,0,1,-1};
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    //ArrayList<Integer> lis = new ArrayList<Integer>();
    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);

        int n=sc.nextInt();
        long ans=0;
        P px[]=new P[n-1];
        P py[]=new P[n-1];
        // int dx[]=new int[n];
        // int dy[]=new int[n];
        Q dx[] = new Q[n];
        Q dy[] = new Q[n];

        for( int i=0; i<n; i++ ){
            dx[i]=new Q(sc.nextInt(),i);
            dy[i]=new Q(sc.nextInt(),i);
        }
        sort(dx);
        sort(dy);

        PriorityQueue<P> que=new PriorityQueue<P>();
        for( int i=0; i<n-1; i++ ){
            que.add(new P(abs(dx[i+1].diff-dx[i].diff), dx[i].id,dx[i+1].id));
            que.add(new P(abs(dy[i+1].diff-dy[i].diff), dy[i].id,dy[i+1].id) );
        }
        QuickUnionWeighted uf=new QuickUnionWeighted(n);
        for( int i=0; i<2*(n-1); i++ ){
            P p=que.poll();
            // db(p.diff,p.id1,p.id2);
            if(uf.connected(p.id1,p.id2))continue;
            ans+=p.diff;
            uf.union(p.id1,p.id2);
            if(uf.sz(p.id1)==n)break;
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

  class QuickUnionWeighted {
     public int[] id;
     private int[] sz;
     public QuickUnionWeighted(int N)
     {
         id = new int[N];
         sz = new int[N];
         for (int i = 0; i < N; i++) {
             id[i] = i;
             sz[i] = 1;
         }
     }
     
     private int root(int p) {
         while (id[p] != p) p = id[p];
         return p;
     }
     
     public boolean connected(int id1, int id2) {
         return root(id1) == root(id2);
     }
     
     public void union(int p, int q) {
         int i = root(p);
         int j = root(q);
         if( i==j )return;
         if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i];   }
         else               { id[j] = i; sz[i] += sz[j];   }  
     }
     public int sz(int x){
         return sz[ root(x) ];// weight
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
    int diff,id1,id2;
    P(int diff, int id1,int id2) {
        this.diff=diff;
        this.id1=id1;
        this.id2=id2;
    } 
      
    public int compareTo(P p){
        return diff - p.diff;
    } 
}

class Q implements Comparable<Q>{
    int diff,id;
    Q(int diff, int id) {
        this.diff=diff;
        this.id=id;
    } 
      
    public int compareTo(Q p){
        return diff - p.diff;
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