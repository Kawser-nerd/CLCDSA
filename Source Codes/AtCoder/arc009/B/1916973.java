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

    void solve()
    {
        int[] b = new int[10];
        for(int i = 0; i < 10; i++){
            b[ni()] = i;
        }
        int n = ni();
        // out.println(n);
        int[][] num = new int[n][];
        for(int i = 0; i < n; i++){
            char[] c = ns().toCharArray();
            num[i] = new int[c.length];
            for(int j = 0; j < c.length; j++){
                num[i][j] = c[j] - '0';
            }
        }
        Arrays.sort(num, new Comparator<int[]>() {
            public int compare(int[] c, int[] d) {
                if(c.length != d.length) return c.length - d.length;
                else{
                    for(int i = 0; i < c.length; i++){
                        if(c[i]==d[i]) continue;
                        else{
                            return b[c[i]] - b[d[i]];
                        }
                    }
                    return 0;
                }
            }
        });
        for(int i = 0; i < n; i++){
            for(int j = 0; j < num[i].length; j++){
                out.print(num[i][j]);
            }
            out.println();
        }

    }

    private long pow(long a, long n, long MOD) {
        a %= MOD;
        if (a == 0) {
            return 0;
        }

        long loop = n;
        long ret = 1;
        long x = a;
        while (loop > 0) {
            if (loop % 2 == 1) {
                ret = ret * x % MOD;
            }
            x = x * x % MOD;
            loop /= 2;
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