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
    List<Integer>[] arr;
    List<Integer>[] arr2;
    boolean[] seen;
    int[] count;
    void solve(){
        char[] s = ns().toCharArray();
        char[] t = ns().toCharArray();
        int sl = s.length;
        int st = t.length;
        int[] sa = new int[sl];
        int[] sb = new int[sl];
        int[] ta = new int[st];
        int[] tb = new int[st];
        for(int i = 0; i < sl; i++){
            if(i>0) sa[i] = sa[i-1];
            if(s[i]=='A') sa[i]++;
            if(i>0) sb[i] = sb[i-1];
            if(s[i]=='B') sb[i]++;
        }
        for(int i = 0; i < st; i++){
            if(i>0) ta[i] = ta[i-1];
            if(t[i]=='A') ta[i]++;
            if(i>0) tb[i] = tb[i-1];
            if(t[i]=='B') tb[i]++;
        }
        int q = ni();
        for(int i = 0; i < q; i++){
            int a = ni()-1;
            int b = ni()-1;
            int c = ni()-1;
            int d = ni()-1;
            int res1 = (sa[b]-(a==0 ? 0 : sa[a-1])) - (sb[b]-(a==0 ? 0 : sb[a-1]));
            int res2 = (ta[d]-(c==0 ? 0 : ta[c-1])) - (tb[d]-(c==0 ? 0 : tb[c-1]));
            if((res1-res2)%3==0) out.println("YES");
            else out.println("NO");
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