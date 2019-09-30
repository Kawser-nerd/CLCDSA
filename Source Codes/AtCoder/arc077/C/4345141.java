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


    void solve(){
        int n = ni();
        int m = ni();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = ni()-1;
        }
        int[][] range = new int[n-1][2];
        long cost = 0;
        for(int i = 0; i < n-1; i++){
            int s = a[i];
            int t = a[i+1];
            if(s<=t){
                range[i][0] = s;
                range[i][1] = t;
            }
            else{
                range[i][0] = s;
                range[i][1] = t+m;
            }
            cost += range[i][1] - range[i][0];
        }

        int[] slist = new int[2*m+1];
        int[] tlist = new int[2*m+1];
        int[] imos = new int[2*m+1];
        long[] tsum = new long[2*m+1];
        int sum = 0;
        for(int i = 0; i < n-1; i++){
            slist[range[i][0]+1]++;
            tlist[range[i][1]]++;
            if(range[i][1]>range[i][0]){
                imos[range[i][0]+1]++;
                imos[range[i][1]]--;
            }
            tsum[range[i][1]] += range[i][1] - range[i][0] - 1;
            if(range[i][1]>=m){
                sum++;
                cost -= (m-range[i][0])-1;
            }
        }
        for(int i = 1; i <= 2*m; i++){
            imos[i] += imos[i-1];
        }
        long ans = cost;
        for(int x = 0; x < m; x++){
            // out.println(x+" "+cost+" "+sum);
            // cost -= sum;
            ans = Math.min(ans, cost);
            // sum += slist[x];
            // sum -= tlist[x];
            // sum -= tlist[x+m];
            sum = imos[x] + imos[x+m];
            cost += tsum[x];
            cost += tsum[x+m];
            cost -= sum;
        }
        out.println(ans);
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