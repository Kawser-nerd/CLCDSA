import java.io.*;
import java.util.*;


class Main {
    static int[][]p;
    static boolean[][]board;
    static List<Integer>added;
    static void add(int x,int y){
        added.add(x*1001+y);
        board[x][y]=true;
    }
    static void solve(int l,int r,int lx,int rx,int ly,int ry,boolean isX){
        if(r-l<=1)return;
        if(isX)xsort(l,r);
        else ysort(l,r);
        int mid=(l+r)/2;
        if(isX){
            int x=p[mid][0];
            int st=mid,en=mid;
            while(st>=l&&p[st][0]==x)st--;
            st++;
            while(en<r&&p[en][0]==x)en++;
            en--;
            boolean[]pres=new boolean[1001];
            for(int i=l;i<r;++i){
                pres[p[i][1]]=true;
            }
            for(int y=1;y<=1000;++y)
                if(pres[y]&&!board[x][y])
                    add(x,y);
            solve(l,st,lx,x-1,ly,ry,!isX);
            solve(en+1,r,x+1,rx,ly,ry,!isX);
        }else{
            int y=p[mid][1];
            int st=mid,en=mid;
            while(st>=l&&p[st][1]==y)st--;
            st++;
            while(en<r&&p[en][1]==y)en++;
            en--;
            boolean[]pres=new boolean[1001];
            for(int i=l;i<r;++i){
                pres[p[i][0]]=true;
            }
            for(int x=1;x<=1000;++x)
                if(pres[x]&&!board[x][y])
                    add(x,y);
            solve(l,st,lx,rx,ly,y-1,!isX);
            solve(en+1,r,lx,rx,y+1,ry,!isX);
        }
    }
    //[l,r)
    static void xsort(int l,int r){
        Arrays.sort(p,l,r,(a,b)->Integer.compare(a[0],b[0]));
    }
    //[l,r)
    static void ysort(int l,int r){
        Arrays.sort(p,l,r,(a,b)->Integer.compare(a[1],b[1]));
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        p=new int[n][2];
        board=new boolean[1001][1001];
        for(int i=0;i<n;++i){
            int x=sc.nextInt();
            int y=sc.nextInt();
            p[i][0]=x;
            p[i][1]=y;
            board[x][y]=true;
        }
        added=new ArrayList<Integer>();
        xsort(0,n);
        solve(0,n,1,1000,1,1000,true);
        if(added.size()>10000-n)throw new Error();
        out.println(added.size());
        for(int a:added){
            out.println((a/1001)+" "+(a%1001));
        }
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
        int[] nextIntArray(int n){
            int[]r=new int[n];
            for(int i=0;i<n;++i)r[i]=nextInt();
            return r;
        }
    }
}