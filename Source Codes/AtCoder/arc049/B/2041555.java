import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long mod = 1_000_000_007;
    long inf = Long.MAX_VALUE;

    int n;
    double[][] res;
    void solve(){
        n = ni();
        res = new double[n][3];
        for(int i = 0; i < n; i++){
            res[i][0] = (double)ni();
            res[i][1] = (double)ni();
            res[i][2] = (double)ni();
        }
        double leftx = -100000;
        double rightx = 100000;
        double reslx = 0;
        double resrx = 0;
        for(int x = 0; x < 100; x++){
            double lx = (leftx+leftx+rightx)/3;
            double rx = (leftx+rightx+rightx)/3;
            double lefty = -100000;
            double righty = 100000;
            for(int y = 0; y < 100; y++){
                double ly = (lefty+lefty+righty)/3;
                double ry = (lefty+righty+righty)/3;
                if(f(lx,ly)>f(lx,ry)) lefty = ly;
                else righty = ry;
            }
            reslx = f(lx,lefty);
            lefty = -100000;
            righty = 100000;
            for(int y = 0; y < 100; y++){
                double ly = (lefty+lefty+righty)/3;
                double ry = (lefty+righty+righty)/3;
                if(f(rx,ly)>f(rx,ry)) lefty = ly;
                else righty = ry;
            }
            resrx = f(rx,lefty);
            if(reslx>resrx) leftx = lx;
            else rightx = rx;
        }
        out.println(reslx);
    }
    double f(double x, double y){
        double ans = 0;
        for(int i = 0; i < n; i++){
            ans = Math.max(ans, res[i][2] * Math.max(Math.abs(x-res[i][0]), Math.abs(y-res[i][1])));
        }
        return ans;
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