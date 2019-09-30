import java.io.*;
import java.util.*;

final class P{
    double x,y;
    P(double a,double b){
        x=a;y=b;
    }
    double dist(P o){
        return Math.sqrt(Math.pow(x-o.x,2)+Math.pow(y-o.y,2));
    }
}
class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        P s=sc.nextP();
        P t=sc.nextP();
        int n=sc.nextInt();
        P[]xy=new P[n];
        double[]r=new double[n];
        for(int i=0;i<n;++i){
            xy[i]=sc.nextP();
            r[i]=sc.nextDouble();
        }
        double[][]d=new double[n+2][n+2];
        d[0][1]=d[1][0]=s.dist(t);
        for(int i=0;i<n;++i)
            d[0][i+2]=d[i+2][0]=Math.max(0,s.dist(xy[i])-r[i]);
        for(int i=0;i<n;++i)
            d[1][i+2]=d[i+2][1]=Math.max(0,t.dist(xy[i])-r[i]);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                d[j+2][i+2]=d[i+2][j+2]=Math.max(0,xy[j].dist(xy[i])-r[i]-r[j]);
        double[]dist=new double[n+2];
        Arrays.fill(dist,1.0/0.0);
        dist[0]=0.0;
        boolean[]det=new boolean[n+2];
        for(int i=0;i<n+2;++i){
            double min=1.0/0.0;
            int minind=-1;
            for(int j=0;j<n+2;++j){
                if(!det[j]&&min>dist[j]){
                    min=dist[j];
                    minind=j;
                }
            }
            assert minind>=0;
            det[minind]=true;
            for(int j=0;j<n+2;++j)
                dist[j]=Math.min(dist[j],min+d[minind][j]);
        }
        out.println(dist[1]);
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
        P nextP(){
            double x=nextDouble();
            double y=nextDouble();
            return new P(x,y);
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