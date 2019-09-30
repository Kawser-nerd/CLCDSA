import java.io.*;
import java.util.*;


class Main {
    ArrayList<Long>[]g;
    int n,m;
    int[]a,b,c;
    boolean[][]used;
    boolean[][]vis;
    int remE=0;
    final void bfs(int vStart,int colorStart){
        Queue<Integer> q=new ArrayDeque<Integer>();
        Queue<Integer> pend=new ArrayDeque<Integer>();
        q.add(vStart*2+colorStart);
        while(q.size()>0||pend.size()>0){
            boolean pending=q.size()==0;
            int vc=pending?pend.poll():q.poll();
            int v=vc/2;
            int color=vc%2;
            if(vis[color][v]){continue;}
            vis[color][v]=true;
            if(vis[1-color][v]){remE=0;return;}
            /*
            System.err.printf("v=%d,col=%d\n",v,color);
            System.err.println("q="+q+" pend="+pend);
            System.err.println("used="+Arrays.deepToString(used));
            */
            for(long wc: g[v]){
                int w=(int)(wc>>>32);
                int ind=(int)wc;
                if(used[color][ind])continue;
                if(c[ind]==color){
                    used[color][ind]=true;
                    remE--;
                    q.add(w*2+(1-color));
                }
                if(c[ind]!=color&&used[1-color][ind]){
                    used[color][ind]=true;
                    q.add(w*2+(1-color));
                }
            }
        }
    }
    final boolean solve(){
        used=new boolean[2][m];
        vis=new boolean[2][n];
        for(int i=0;i<n;++i){
            for(int b=0;b<2;++b){
                remE=m;
                Arrays.fill(used[0],false);
                Arrays.fill(used[1],false);
                Arrays.fill(vis[0],false);
                Arrays.fill(vis[1],false);
                bfs(i,b);
                assert remE>=0;
                if(remE==0){
                    //System.err.println("Success "+i + " col="+b);
                    return true;
                }
            }
        }
        return false;
    }
    Main(int n,int[]a,int[]b,int[]c){
        g=new ArrayList[n];
        Arrays.setAll(g,x->new ArrayList<Long>());
        this.n=n;
        this.m=a.length;
        this.a=a;
        this.b=b;
        this.c=c;
        for(int i=0;i<m;++i){
            g[a[i]].add((long)b[i]<<32|i);
            g[b[i]].add((long)a[i]<<32|i);
        }
        out.println(solve()?"Yes":"No");
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[m],b=new int[m],c=new int[m];
        for(int i=0;i<m;++i){
            a[i]=sc.nextInt()-1;
            b[i]=sc.nextInt()-1;
            c[i]=sc.next().equals("r")?0:1;
        }
        new Main(n,a,b,c);
        out.close();
    }
    // http://codeforces.com/blog/entry/7018
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.