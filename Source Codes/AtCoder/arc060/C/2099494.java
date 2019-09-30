import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    int mod = 1_000_000_007;
    int inf = Integer.MAX_VALUE;

    void solve(){
        int n = ni();
        long[] x = new long[n];
        TreeSet<Long> set = new TreeSet<>();
        HashMap<Long, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            x[i] = ni();
            set.add(x[i]);
            map.put(x[i], i);
            if(i==n-1){
                set.add(x[i]+1);
                map.put(x[i]+1, i+1);
            }
        }
        long l = nl();
        int[][] step = new int[n+1][20];
        for(int i = 0; i < n; i++){
            long tmp = x[i] + l + 1;
            step[i][0]= map.get(set.headSet(tmp, false).last());
        }
        step[n][0] = n;
        for(int i = 1; i < 20; i++){
            for(int j = 0; j <= n; j++){
                step[j][i] = step[step[j][i-1]][i-1];
                // out.print(step[j][i]+" ");
            }
            // out.println();
        }
        int q = ni();
        for(int i = 0; i < q; i++){
            int from = ni()-1;
            int to = ni()-1;
            if(from > to){
                int tmp = from;
                from = to;
                to = tmp;
            }
            int tmp = from;
            int ans = 0;
            int res = 0;
            for(int j = 19; j >= 0; j--){
                int now = step[tmp][j];
                if(now >= to){
                    ans = res + (int)Math.pow(2,j);
                    continue;
                }
                if(now < to){
                    // out.println(i+" "+j+" "+now);
                    tmp = now;
                    res += (int)Math.pow(2,j);
                    continue;
                }
            }
            out.println(ans);
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