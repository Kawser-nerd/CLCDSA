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
        int q = ni();
        SegmentTree seg = new SegmentTree();
        for(int i = 0; i < q; i++){
            int t = ni();
            int x = ni();
            if(t==1) seg.update(x,1);
            if(t==2){
                long left = 0;
                long right = 200000;
                while(right-left>1){
                    long mid = (left+right)/2;
                    long res = seg.query(0,(int)mid+1);
                    if(res<x) left = mid;
                    else right = mid;
                }
                out.println(left+1);
                seg.update((int)left+1,-1);
            }
            // out.println(seg.query(0,x+1));
        }
    }

    class SegmentTree {
        int SIZE = 1 << 18;
        long[][] seg;
        SegmentTree() {
            this.seg = new long[2 * SIZE][1];
            for(int i=0;i<2*SIZE;++i){
                seg[i][0] = 0;
            }
        }
        void update(int x, long value) {
            x += SIZE - 1;
            this.seg[x][0] += value;
            while (x > 0) {
                x = (x - 1) / 2;
                this.seg[x][0] = this.seg[2 * x + 1][0] + this.seg[2 * x + 2][0];
            }
        }
        long query(int a,int b,int l,int r,int k){
            if(a<=l&&r<=b) return seg[k][0];
            if(b<=l||r<=a) return 0;
            long ans1=query(a,b,l,(l+r)/2,2*k+1);
            long ans2=query(a,b,(l+r)/2,r,2*k+2);
            return ans1+ans2;
        }
        long query(int l, int r) {
            return query(l,r,0,SIZE,0);
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