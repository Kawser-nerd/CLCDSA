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

    void solve(){
        int n = ni();
        int m = ni();
        int[][] range = new int[n][3];
        int[] span = new int[n];
        for(int i = 0; i < n; i++){
            int l = ni();
            int r = ni();
            range[i] = new int[]{l,r,r-l+1};
            span[i] = r-l+1;
        }
        Arrays.sort(range, (a,b)->a[2]-b[2]);
        Arrays.sort(span);
        LazySegmentTree seg = new LazySegmentTree(m);
        int cur = 0;
        for(int d = 1; d <= m; d++){
            int ub = upperBound(span,d);
            int ans = n-1-ub;
            for(int i = cur; i <= ub; i++){
                seg.update(range[i][0], range[i][1]+1, 1);
            }
            for(int j = 0; j <= m; j+=d){
                ans+=seg.query(j,j+1);
            }
            cur = ub+1;
            out.println(ans);
        }

    }

    class LazySegmentTree {
        int n;
        long[] seg;
        long[] lazy;
        LazySegmentTree(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            this.seg = new long[this.n<<1];
            this.lazy = new long[this.n<<1];
        }
        long comb(long a, long b){
            return a+b;
        }
        long query(int a,int b,int l,int r,int k){
            eval(l,r,k);
            if(a<=l&&r<=b) return seg[k];
            if(b<=l||r<=a) return 0;
            long ans1=query(a,b,l,(l+r)/2,2*k+1);
            long ans2=query(a,b,(l+r)/2,r,2*k+2);
            return comb(ans1,ans2);
        }
        long query(int l, int r) {
            return query(l,r,0,n,0);
        }
        void eval(int l, int r, int k){
            if(this.lazy[k]!= 0){
                this.seg[k] += this.lazy[k];
                if(r-l>1){
                    this.lazy[2*k+1] += this.lazy[k];
                    this.lazy[2*k+2] += this.lazy[k];
                }
                this.lazy[k] = 0;
            }
        }
        void update(int a, int b, long x, int l, int r, int k){
            eval(l,r,k);
            if(b<=l||r<=a) return;
            if(a<=l&&r<=b){
                this.lazy[k] += x;
                eval(l,r,k);
            }
            else{
                update(a,b,x,l,(l+r)/2,2*k+1);
                update(a,b,x,(l+r)/2,r,2*k+2);
                this.seg[k] = comb(this.seg[2*k+1],this.seg[2*k+2]);
            }
        }
        void update(int a, int b, long x){
            update(a, b, x, 0, n, 0);
        }
    }            

    public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
    public static int lowerBound(int[] a, int l, int r, int v)
    {
        if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
        int low = l-1, high = r;
        while(high-low > 1){
            int h = high+low>>>1;
            if(a[h] >= v){
                high = h;
            }else{
                low = h;
            }
        }
        return high;
    }

    public static int upperBound(int[] a, int v){ return upperBound(a, 0, a.length, v); }
    public static int upperBound(int[] a, int l, int r, int v)
    {
        if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
        int low = l-1, high = r;
        while(high-low > 1){
            int h = high+low>>>1;
            if(a[h] >= v){
                high = h;
            }else{
                low = h;
            }
        }
        return low;
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