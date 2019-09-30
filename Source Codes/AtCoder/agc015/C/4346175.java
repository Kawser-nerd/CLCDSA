import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    static int mod = 1_000_000_007;
    // int mod = 998244353;
    long inf = Long.MAX_VALUE/2;


    void solve(){
        int n = ni();
        int m = ni();
        int q = ni();
        char[][] map = nm(n,m);
        int[][] bnum = new int[n+1][m+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bnum[i+1][j+1] = bnum[i][j+1] +  bnum[i+1][j] - bnum[i][j] + (map[i][j]=='1' ? 1 : 0);
            }
        }
        int[][] vcnum = new int[n+1][m+1];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = 1;
                if(map[i][j]=='0'||map[i-1][j]=='0') val = 0;
                vcnum[i+1][j+1] = vcnum[i][j+1] +  vcnum[i+1][j] - vcnum[i][j] + val;
            }
        }
        int[][] hcnum = new int[n+1][m+1];
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                int val = 1;
                if(map[i][j]=='0'||map[i][j-1]=='0') val = 0;
                hcnum[i+1][j+1] = hcnum[i][j+1] +  hcnum[i+1][j] - hcnum[i][j] + val;
            }
        }
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= m; j++){
        //         out.print(vcnum[i][j]);
        //     }
        //     out.println();
        // }
        // out.println(vcnum[n][m]);

        for(int i = 0; i < q; i++){
            int lx = ni()-1;
            int ly = ni()-1;
            int rx = ni()-1;
            int ry = ni()-1;
            int sum = bnum[rx+1][ry+1] - bnum[lx][ry+1] - bnum[rx+1][ly] + bnum[lx][ly];
            int vc = vcnum[rx+1][ry+1] - vcnum[lx+1][ry+1] - vcnum[rx+1][ly] + vcnum[lx+1][ly];
            int hc = hcnum[rx+1][ry+1] - hcnum[lx][ry+1] - hcnum[rx+1][ly+1] + hcnum[lx][ly+1];
            out.println(sum-vc-hc);
            // out.println(sum+" "+vc+" "+hc);
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