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
    boolean flag = false;

    void solve(){
        int k = ni();
        int m = ni();
        long[] a = new long[k];
        long[] c = new long[k];
        for(int i = 0; i < k; i++)a[k-1-i] = nl();
        for(int i = 0; i < k; i++)c[i] = nl();
        long[][] A = new long[k][k];
        for(int i = 0; i < k; i++){
            A[0][i] = c[i];
        }
        for(int i = 0; i < k-1; i++){
            A[i+1][i] = (1l<<32) - 1;
        }
        long[] ans = pow(A,a,m-k);
        out.println(m-k>0 ? ans[0] : a[k-m]);

    }
    
    // A^e*v
    long[] pow(long[][] A, long[] v, int e)
    {
        long[][] MUL = A;
        for(;e > 0;e>>>=1) {
            if((e&1)==1)v = mul(MUL, v);
            MUL = p2(MUL);
        }
        return v;
    }
    
    // int matrix*int vector
    long[] mul(long[][] A, long[] v)
    {
        int m = A.length;
        int n = v.length;
        long[] w = new long[m];
        for(int i = 0;i < m;i++){
            long sum = 0;
            for(int k = 0;k < n;k++){
                sum ^= A[i][k] & v[k];
            }
            w[i] = sum;
        }
        return w;
    }
    
    // int matrix^2 (be careful about negative value)
    long[][] p2(long[][] A)
    {
        int n = A.length;
        long[][] C = new long[n][n];
        for(int i = 0;i < n;i++){
            long[] sum = new long[n];
            for(int k = 0;k < n;k++){
                for(int j = 0;j < n;j++){
                    sum[j] ^= A[i][k] & A[k][j];
                }
            }
            for(int j = 0;j < n;j++){
                C[i][j] = sum[j];
            }
        }
        return C;
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