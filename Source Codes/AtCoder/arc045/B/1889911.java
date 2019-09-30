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
        int n = ni();
        int m = ni();
        LazySegmentTree seg = new LazySegmentTree();
        int[] s = new int[m];
        int[] g = new int[m];
        for(int i = 0; i < m; i++){
            s[i] = ni()-1;
            g[i] = ni()-1;
            seg.add(s[i],g[i]+1,1);
        }
        List<Integer> arr = new ArrayList<>();
        // for(int i = 0; i < 10; i++){
        //     out.println(seg.query(i,i+1));
        // }
        for(int i = 0; i < m; i++){
            // out.println(seg.query(s[i],g[i]+1));
            if(seg.query(s[i],g[i]+1)>=2) arr.add(i+1);
        }
        out.println(arr.size());
        for(int i : arr){
            out.println(i);
        }
        

    }

   class LazySegmentTree {
        int SIZE = 1 << 20;
        long[][] seg;
        LazySegmentTree() {
            this.seg = new long[2 * SIZE][2];
            for(int i=0;i<2*SIZE;++i){
                seg[i][0] = 0;
                seg[i][1] = 0;
            }
        }
        // void update(int x, long value) {
        //     x += SIZE - 1;
        //     this.seg[x][0] += value;
        //     while (x > 0) {
        //         x = (x - 1) / 2;
        //         this.seg[x][0] = this.seg[2 * x + 1][0] + this.seg[2 * x + 2][0];
        //     }
        // }
        long query(int a,int b,int l,int r,int k){
            eval(l,r,k);
            if(a<=l&&r<=b) return seg[k][0];
            if(b<=l||r<=a) return inf;
            long ans1=query(a,b,l,(l+r)/2,2*k+1);
            long ans2=query(a,b,(l+r)/2,r,2*k+2);
            return Math.min(ans1,ans2);
        }
        long query(int l, int r) {
            return query(l,r,0,SIZE,0);
        }
        void eval(int l, int r, int k){
            if(this.seg[k][1]!=0){
                this.seg[k][0] += this.seg[k][1];
                if(r-l>1){
                    this.seg[2*k+1][1] += this.seg[k][1];
                    this.seg[2*k+2][1] += this.seg[k][1];
                }
                this.seg[k][1] = 0;
            }
        }
        void add(int a, int b, long x, int l, int r, int k){
            eval(l,r,k);
            if(b<=l||r<=a) return;
            if(a<=l&&r<=b){
                this.seg[k][1] += x;
                eval(l,r,k);
            }
            else{
                add(a,b,x,l,(l+r)/2,2*k+1);
                add(a,b,x,(l+r)/2,r,2*k+2);
                this.seg[k][0] = Math.min(this.seg[2*k+1][0],this.seg[2*k+2][0]);
            }
        }
        void add(int a, int b, long x){
            add(a, b, x, 0, SIZE, 0);
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