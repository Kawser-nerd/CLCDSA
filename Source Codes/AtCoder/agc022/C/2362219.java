import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long mod = 1_000_000_007;
    long inf = Long.MAX_VALUE/100;

    void solve(){
        int n = ni();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i = 0; i < n; i++) a[i] = ni();
        for(int i = 0; i < n; i++) b[i] = ni();
        long[][] dist = new long[51][51];
        int[][] line = new int[51][51];
        for(int i = 0; i <= 50; i++) Arrays.fill(dist[i], inf);
        for(int i = 0; i <= 50; i++){
            for(int j = 1; j <= 50; j++){
                int t = i%j;
                dist[i][t] = 0;
                line[i][t]++;
            }
        }
        for(int i = 0; i <= 50; i++){
            line[i][i]++;
        }
        long ans = 0;
        for(int c = 50; c >= 1; c--){
            long[][] disttmp = new long[51][51];
            for(int i = 0; i <= 50; i++) Arrays.fill(disttmp[i], inf);
            for(int i = 0; i <= 50; i++){
                for(int j = 1; j <= 50; j++){
                    int t = i%j;
                    if(t==(i%c) && line[i][t]<=1){
                        disttmp[i][t] = inf;
                    }
                    else disttmp[i][t] = dist[i][t];
                }
            }
            for (int k = 0; k <= 50; k++) {
                for (int i = 0; i <= 50; i++) {
                    for (int j = 0; j <= 50; j++) {
                        if (disttmp[i][j] > disttmp[i][k] + disttmp[k][j]) {
                            disttmp[i][j] = disttmp[i][k] + disttmp[k][j];
                        }
                    }
                }
            }
            boolean flag = true;
            for(int i = 0; i < n; i++){
                if(disttmp[a[i]][b[i]]>=inf){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int i = 0; i <= 50; i++){
                    int t = i%c;
                    line[i][t]--;
                    if(line[i][t]==0) dist[i][t] = inf;
                }
            }
            else{
                ans += (long)Math.pow(2,c);
            }
            // else{
            //     for(int i = 0; i <= 50; i++){
            //         for(int j = 0; j <= 50; j++){
            //             long tmp = dist[i][j]>=inf ? -1 : dist[i][j];
            //             out.print(line[i][j]+" ");
            //         }
            //         out.println();
            //     }
            // }
        }
        for (int k = 0; k <= 50; k++) {
            for (int i = 0; i <= 50; i++) {
                for (int j = 0; j <= 50; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dist[a[i]][b[i]]>=inf){
                out.println(-1);
                return;
            }
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