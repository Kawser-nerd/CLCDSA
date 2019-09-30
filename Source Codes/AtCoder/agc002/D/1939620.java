import java.io.*;
import java.util.*;


class Main {
    static int[]disj,size;
    static void init(int n){
        disj=new int[n];
        size=new int[n];
        reset();
    }
    static void reset(){
        int n=disj.length;
        for(int i=0;i<n;++i){
            disj[i]=i;
            size[i]=1;
        }
    }
    static int root(int x){
        if(disj[x]==x)return x;
        return disj[x]=root(disj[x]);
    }
    static int size(int x){
        return size[root(x)];
    }
    static void unify(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)
            return;
        assert size[x]>0;
        assert size[y]>0;
        if(size[x]<size[y]){
            int t=x;
            x=y;
            y=t;
        }
        size[x]+=size[y];
        size[y]=0;
        disj[y]=x;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[m],b=new int[m];
        for(int i=0;i<m;++i){
            a[i]=sc.nextInt()-1;
            b[i]=sc.nextInt()-1;
        }
        int q=sc.nextInt();
        int[]x=new int[q],y=new int[q],z=new int[q];
        for(int i=0;i<q;++i){
            x[i]=sc.nextInt()-1;
            y[i]=sc.nextInt()-1;
            z[i]=sc.nextInt();
        }
        int[]parf=new int[q],parp=new int[q];
        Arrays.fill(parp,m);
        Arrays.fill(parf,-1);
        long[]salva=new long[q];
        init(n);
        int taplis=20;
        while(taplis-->0){
            Arrays.fill(salva,-1);
            for(int j=0;j<q;++j){
                if(parp[j]-parf[j]>1)
                    salva[j]=(long)((parp[j]+parf[j])/2)<<32|j;
            }
            Arrays.sort(salva);
            reset();
            int cpos=0;
            for(int j=0;j<m;++j){
                unify(a[j],b[j]);
                while(cpos<q&&salva[cpos]<(long)j<<32)cpos++;
                while(cpos<q&&j==salva[cpos]>>>32){
                    int ind=(int)salva[cpos];
                    boolean ok=(root(x[ind])==root(y[ind])?size(x[ind]):
                                size(x[ind])+size(y[ind]))>=z[ind];
                    if(ok)parp[ind]=j;
                    else parf[ind]=j;
                    cpos++;
                }
            }
        }
        for(int i=0;i<q;++i)
            out.println(parp[i]+1);
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