import java.io.*;
import java.util.*;


class Main {
    static final long I=1L<<48;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        long[][]cost=new long[n][n];
        for(int i=0;i<n;++i)
            Arrays.fill(cost[i],0);
        long ctotal=0;
        for(int i=0;i<m;++i){
            int a=sc.nextInt()-1;
            int b=sc.nextInt()-1;
            int c=sc.nextInt();
            cost[a][b]=c;
            cost[b][a]=c;
            ctotal+=c;
        }
        long[]ext=new long[1<<n];
        ext[0]=-I;
        for(int b=1;b<1<<n;++b){
            long t=0;
            for(int i=0;i<n;++i)
                if((b&1<<i)!=0)
                    for(int j=0;j<i;++j)
                        if((b&1<<j)!=0)
                            t+=cost[i][j];
            ext[b]=t;
        }
        //System.err.println(Arrays.toString(ext));
        long[][]dp=new long[n][1<<n];
        long[][]dpnxt=new long[n][1<<n];
        for(int i=0;i<n;++i)
            Arrays.fill(dp[i],-I);
        for(int i=0;i<n;++i)
            Arrays.fill(dpnxt[i],-I);
        dpnxt[0][0]=0;
        for(int b=1;b<1<<n;++b)
            for(int i=0;i<n;++i){
                long ma=-I;
                if((b&1<<i)==0)continue;
                int s=b^1<<i;
                while(true){
                    ma=Math.max(ma,dpnxt[i][s]+ext[b^s]);
                    if(s==0)break;
                    s=(s-1)&(b^1<<i);
                }
                //System.err.println("dp["+i+"]["+b+"]="+ma);
                dp[i][b]=ma;
                for(int j=0;j<n;++j){
                    if((b&1<<j)==0&&cost[i][j]>0)
                        dpnxt[j][b]=Math.max(dpnxt[j][b],ma+cost[i][j]);
                }
            }
        out.println(ctotal-dp[n-1][(1<<n)-1]);
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
}