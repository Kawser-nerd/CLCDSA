import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE/2;

    void solve(){
        int[] s = new int[]{ni(), ni()};
        int[] g = new int[]{ni(), ni()};
        int minx= Math.min(s[0],g[0]);
        int maxx= Math.max(s[0],g[0]);
        int miny= Math.min(s[1],g[1]);
        int maxy= Math.max(s[1],g[1]);
        int n = ni();
        int[][] m = new int[n][2];
        for(int i = 0; i < n; i++){
            m[i][0] = ni();
            m[i][1] = ni();
        }
        Arrays.sort(m, (a,b)-> a[0]-b[0]);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(m[i][0]>=minx&&m[i][0]<=maxx&&m[i][1]>=miny&&m[i][1]<=maxy){
                res++;
            }
        }
        int[] a1 = new int[res];
        int res2 = 0;
        for(int i = 0; i < n; i++){
            if(m[i][0]>=minx&&m[i][0]<=maxx&&m[i][1]>=miny&&m[i][1]<=maxy){
                a1[res2] = m[i][1];
                res2++;
            }
        }
        int L = 0;
        if(s[0]<=g[0]&&s[1]<=g[1]) L = lis(a1);
        else if(g[0]<=s[0]&&g[1]<=s[1]) L = lis(a1);
        else{
            for(int i = 0; i < res; i++){
                a1[i] = -a1[i];
            }
            L = lis(a1);
        }
        double ans = (double)((maxx-minx)+(maxy-miny))*100;
        ans -= L*(20-Math.PI*5);
        if(L==Math.min(maxx-minx, maxy-miny)+1) ans = ans + Math.PI*5;
        out.printf("%.15f\n",ans);
    }

    public static int lis(int[] in)
    {
        int n = in.length;
        int ret = 0;
        int[] h = new int[n + 1];
        Arrays.fill(h, Integer.MIN_VALUE / 2);
        for(int i = 0;i < n;i++){
            int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
            if(ind < 0){
                ind = -ind-2;
                h[ind+1] = in[i];
                if(ind >= ret)ret++;
            }
        }
        return ret;
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