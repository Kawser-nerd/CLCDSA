import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    // static int mod = 1_000_000_007;
    int mod = 998244353;
    long inf = Long.MAX_VALUE/2;

    void solve(){
        char[] c = ns().toCharArray();
        int n = c.length;
        int[] s = new int[n];
        for(int i = 0; i < n; i++){
            if(c[i]=='a') s[i] = 0;
            if(c[i]=='b') s[i] = 1;
            if(c[i]=='c') s[i] = 2;
        }
        long ans = 0;
        if(n==1){
            out.println(1);
            return;
        }
        if(n==2){
            if(s[0]==s[1]){
                out.println(1);
                return;
            }
            else{
                out.println(2);
                return;
            }
        }
        if(n==3){
            boolean[] seen = new boolean[1000];
            Deque<int[]> q = new ArrayDeque<>();
            q.push(s);
            while(!q.isEmpty()){
                int[] t = q.poll();
                int tv = t[0]*100+t[1]*10+t[2];
                seen[tv] = true;
                // out.println(tv);
                ans++;
                if(t[0]!=t[1]){
                    int v = 3-(t[0]+t[1]);
                    int[] t2 = new int[]{v,v,t[2]};
                    int t2v = v*100+v*10+t[2];
                    if(!seen[t2v]) q.push(t2);
                    seen[t2v] = true;
                }
                if(t[1]!=t[2]){
                    int v = 3-(t[1]+t[2]);
                    int[] t2 = new int[]{t[0],v,v};
                    int t2v = t[0]*100+v*10+v;
                    if(!seen[t2v]) q.push(t2);
                    seen[t2v] = true;
                }
            }
            out.println(ans);
            return;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i]!=s[i+1]) break;
            if(i==n-2){
                out.println(1);
                return;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += s[i];
        }
        sum %= 3;
        long[][][][] dp = new long[n][3][3][2];
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < 3; j++){
        //         for(int k = 0; k < 3; k++){
        //             for(int l = 0; l < 2; l++){
        //                 dp[i][j][k][l] = -1;
        //             }
        //         }
        //     }
        // }
        dp[0][0][0][0] = 1;
        dp[0][1][1][0] = 1;
        dp[0][2][2][0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    dp[i][j][k][0] = dp[i-1][(j+1)%3][(k-j+3)%3][0] + dp[i-1][(j+2)%3][(k-j+3)%3][0];
                    dp[i][j][k][1] = dp[i-1][j][(k-j+3)%3][0] + dp[i-1][j][(k-j+3)%3][1] + 
                    dp[i-1][(j+1)%3][(k-j+3)%3][1] + dp[i-1][(j+2)%3][(k-j+3)%3][1];
                    dp[i][j][k][0] %= mod;
                    dp[i][j][k][1] %= mod;
                }
            }
        }
        for(int j = 0; j < 3; j++){
            ans += dp[n-1][j][sum][1];
            ans %= mod;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i]==s[i+1]) break;
            if(i==n-2) ans++;
        }
        out.println(ans);
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