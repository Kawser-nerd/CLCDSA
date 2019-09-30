import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[m],del=new int[m];
        int e=0,o=m;
        for(int i=0;i<m;++i)a[i]=sc.nextInt();
        for(int i=0;i<m;++i){
            if(a[i]%2==0)del[e++]=a[i];
            else del[--o]=a[i];
        }
        if(o<m-2){
            out.println("Impossible");
            out.close();
            return;
        }
        int[]b;
        if(o==m){
            b=new int[m+1];
            b[0]=a[0]-1;
            for(int i=1;i<m;++i)b[i]=a[i];
            b[m]=1;
        }else if(o==m-1){
            System.arraycopy(del,0,a,0,m);
            b=new int[a[m-1]==1?m:m+1];
            b[0]=1;
            for(int i=0;i<m-1;++i)
                b[i+1]=a[i];
            if(a[m-1]!=1)
                b[m]=a[m-1]-1;
        }else{
            a[0]=del[m-2];
            a[m-1]=del[m-1];
            for(int i=0;i<m-2;++i)a[i+1]=del[i];
            b=new int[a[m-1]==1?m-1:m];
            b[0]=a[0]+1;
            for(int i=1;i<m-1;++i)
                b[i]=a[i];
            if(a[m-1]!=1)
                b[m-1]=a[m-1]-1;
        }
        for(int i=0;i<m;++i)
            out.print(a[i]+(i==m-1?"\n":" "));
        out.println(b.length);
        for(int i=0;i<b.length;++i)
            out.print(b[i]+(i==b.length-1?"\n":" "));
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