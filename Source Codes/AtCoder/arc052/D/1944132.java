import java.io.*;
import java.util.*;


class Main {
    static long k;
    static long dif(long n,long bias){
        long v=n*bias,c=n;
        while(c>0){
            v-=c%10;
            c/=10;
        }
        v%=k;
        if(v<0)v+=k;
        return v;
    }
    static void taplis(Map<Long,Integer>hm,int n,long bias){
        for(int i=0;i<n;++i){
            long v=dif(i,bias);
            if(!hm.containsKey(v))
                hm.put(v,1);
            else
                hm.put(v,hm.get(v)+1);
        }
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        k=sc.nextLong();
        long m=sc.nextLong()+1;
        long q=m/100000;
        int r=(int)(m%100000);
        Map<Long,Integer>up=new HashMap<Long,Integer>();
        Map<Long,Integer>down=new HashMap<Long,Integer>();
        Map<Long,Integer>res=new HashMap<Long,Integer>();
        taplis(up,(int)q,100000%k);
        taplis(down,100000,1);
        taplis(res,r,1);
        long ans=0;
        for(Map.Entry<Long,Integer> e:up.entrySet()){
            long fst=e.getKey();
            int v=e.getValue();
            long snd=(k-fst)%k;
            if(down.containsKey(snd))
                ans+=(long)v*(long)down.get(snd);
        }
        long difQ=dif(q,100000%k);
        for(Map.Entry<Long,Integer> e:res.entrySet()){
            if((difQ+e.getKey())%k==0){
                ans+=e.getValue();
            }
        }
        out.println(ans-1);
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