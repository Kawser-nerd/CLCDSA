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

    void solve(){
        int n = ni();
        int a = ni()-1;
        char[] K = ns().toCharArray();
        int[] k = new int[K.length];
        for(int i = 0; i < K.length; i++){
            k[i] = K[i] - '0';
        }
        int[] b = new int[n];
        for(int i = 0; i < n; i++){
            b[i] = ni()-1;
        }
        int[] res = new int[2];
        int start = a;
        int[] seen = new int[n];
        int s = a;
        while(true){
            seen[s]++;
            if(seen[s]==1) res[0]++;
            if(seen[s]==2){
                if(res[1]==0) start = s;
                res[1]++;
            }
            if(seen[s]==3) break;
            int c = b[s];
            s = c;
        }
        // out.println(res[0]+" "+res[1]);
        // out.println(start);
        long tmp = 0;
        for(int i = 0; i < k.length; i++){
            tmp = tmp*10+k[i];
            if(tmp>res[0]) break;
        }
        int ans = a;
        // out.println(a+" "+tmp);
        if(tmp<=res[0]){
            for(int i = 0; i < tmp; i++){
                ans = b[ans];
            }
            out.println(ans+1);
            return;
        }
        long m = 0;
        for(int i = 0; i < k.length; i++){
            m = (m*10+k[i])%res[1];
        }
        m = (m+10000*res[1]-res[0])%res[1];
        // out.println(m);
        ans = start;
        for(int i = 0; i < m; i++){
                ans = b[ans];
            }
        out.println(ans+1);
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