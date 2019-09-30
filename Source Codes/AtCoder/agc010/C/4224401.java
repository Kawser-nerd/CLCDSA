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

    ArrayList<Integer>[] edge;
    long[] a;
    void solve(){
        int n = ni();
        a = new long[n];
        for(int i = 0; i < n; i++){
            a[i] = nl();
        }

        edge = new ArrayList[n];
        for(int i = 0; i < n; i++){
            edge[i] = new ArrayList<>();
        }
        for(int i = 0; i < n-1; i++){
            int s = ni()-1;
            int t = ni()-1;
            edge[s].add(t);
            edge[t].add(s);
        }  
        if(n==2){
            System.out.println(a[0]==a[1] ? "YES" : "NO");
            return;
        }
        int source = -1; 
        for(int i = 0; i < n; i++){
            if(edge[i].size()>=2){
                source = i;
                break;
            }
        }
        long res = f(source,  -1);
        System.out.println(res==0 ? "YES" : "NO");

    }

    long f(int c, int p){
        long sum = 0;
        long ma = 0;

        boolean seen = false;
        for(int e : edge[c]){
            if(e==p) continue;
            long tmp = f(e, c);
            ma = Math.max(ma, tmp);
            sum += tmp;
            seen = true;
        }

        if(!seen) return a[c];

        long t = 2*a[c] - sum;
        long d = a[c]-t;
        ma -= t;
        sum -= t;

        long q = 0;
        if(ma>=sum/2) q = sum-ma;
        else q = sum/2;

        // System.out.println(c+" "+t+" "+ma+" "+sum);
        if(d!=q || sum%2==1 || t < 0 || d < 0){
            System.out.println("NO");
            System.exit(0);
        }
        return t;
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
 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.