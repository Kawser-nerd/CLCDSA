import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE;
    void solve()
    {
        int n = ni();
        int W = ni();
        long[] v = new long[n];
        long[] w = new long[n];
        long vmax = 0;
        long wmax = 0;
        for(int i = 0; i < n; i++){
            v[i] = nl();
            w[i] = nl();
            vmax = Math.max(vmax,v[i]);
            wmax = Math.max(wmax,w[i]);
        }
        if(n<=30){
            long[][] a1 = new long[1<<(n/2)][2];
            long[][] a2 = new long[1<<(n-n/2)][2];
            for(int i = 0; i < 1<<(n/2); i++){
                for(int j = 0; j < n/2; j++){
                    if((i>>j)%2==1){
                        a1[i][0] += v[j];
                        a1[i][1] += w[j];
                    }
                }
            }
            Arrays.sort(a1, new Comparator<long[]>() {
                public int compare(long[] a, long[] b) {
                    if(a[1] != b[1])return  Long.compare(a[1],b[1]);
                    return Long.compare(a[0],b[0]);
                }
            });
            long VM = 0;
            for(int i = 0; i < 1<<(n/2); i++){
                if(a1[i][0]<VM){
                    a1[i][0] = 0;
                    a1[i][1] = 0;
                    continue;
                }
                VM = a1[i][0];
            }
            Arrays.sort(a1, new Comparator<long[]>() {
                public int compare(long[] a, long[] b) {
                    if(a[1] != b[1])return  Long.compare(a[1],b[1]);
                    return Long.compare(a[0],b[0]);
                }
            });
             for(int i = 0; i < 1<<(n-n/2); i++){
                for(int j = 0; j < n-n/2; j++){
                    if((i>>j)%2==1){
                        a2[i][0] += v[j+n/2];
                        a2[i][1] += w[j+n/2];
                    }
                }
            }
            Arrays.sort(a2, new Comparator<long[]>() {
                public int compare(long[] a, long[] b) {
                    if(a[1] != b[1])return  Long.compare(a[1],b[1]);
                    return Long.compare(a[0],b[0]);
                }
            });
            VM = 0;
            long ans = 0;
            for(int i = 0; i < 1<<n-(n/2); i++){
                if(a2[i][0]<VM){
                    a2[i][0] = 0;
                    a2[i][1] = 0;
                    continue;
                }
                VM = a2[i][0];
                long TW = W - a2[i][1];
                if(TW<0) continue;
                int left = 0;
                int right = 1<<(n/2);
                while(left+1<right){
                    int res = (left+right)/2;
                    if(a1[res][1]<=TW) left = res;
                    else right = res;
                }
                // out.println(TW+" "+a1[left][0] + " " + a1[left][1]);
                ans = Math.max(ans, VM + a1[left][0]);
            }
            out.println(ans);
        }
        else if(wmax <= 1000){
            long[][] dp = new long[201][201001];
            dp[0][0]=0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j<= 200000; j++){
                    dp[i+1][j] = dp[i][j];
                }
                for(int j = 0; j<= 200000; j++){
                    dp[i+1][j+(int)w[i]] = Math.max(dp[i+1][j+(int)w[i]], dp[i][j]+v[i]); 
                }
            }
            long ans = 0;
            for(int i = 0; i <= W; i++){
                ans = Math.max(ans, dp[n][i]);
            }
            out.println(ans);
        }
        else if(vmax <= 1000){
            long[][] dp = new long[201][201001];
            for(int i = 0; i <= 200; i++){
                Arrays.fill(dp[i],inf);
            }
            dp[0][0]=0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j<= 200000; j++){
                    dp[i+1][j] = dp[i][j];
                }
                for(int j = 0; j<= 200000; j++){
                    dp[i+1][j+(int)v[i]] = Math.min(dp[i+1][j+(int)v[i]], dp[i][j]+w[i]); 
                }
            }
            long ans = 0;
            for(int i = 0; i <= 200000; i++){
                if(dp[n][i]<=W) ans = i;
            }
            out.println(ans);
        }

 
    }
    
    
    void run() throws Exception
    {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
    
    public static void main(String[] args) throws Exception { new Main().run(); }
    
    private byte[] inbuf = new byte[1024];
    private int lenbuf = 0, ptrbuf = 0;
    
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b) && b != ' ')){
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
 
}