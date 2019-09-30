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
        int n = ni();
        int k = ni();
        arr = new ArrayList[n+1];
        arr2 = new ArrayList[n+1];
        for(int i = 0; i < n+1; i++){
            arr[i] = new ArrayList<>();
            arr2[i] = new ArrayList<>();
        }
        for(int i = 0; i < n-1; i++){
            int from = ni()-1;
            int to = ni()-1;
            arr[from].add(to);
            arr[to].add(from);
            arr2[i].add(from);
            arr2[i].add(to);
        }
        int ans = inf;
        if(k%2==0){
            for(int i = 0; i < n; i++){
                seen = new boolean[n];
                count = new int[n];
                f(i,0);
                int res = 0;
                for(int j = 0; j < n; j++){
                    // out.println(count[j]);
                    if(count[j]>k/2){
                        res += 1;
                    }
                }
                // out.println(res);
                ans = Math.min(ans, res);
            }
        }
        else{
            for(int i = 0; i < n-1; i++){
                seen = new boolean[n+1];
                count = new int[n+1];
                int f = arr2[i].get(0);
                int t = arr2[i].get(1);
                arr[f].remove(arr[f].indexOf(t));
                arr[t].remove(arr[t].indexOf(f));
                arr[n].add(f);
                arr[n].add(t);
                f(n,0);
                int res = 0;
                for(int j = 0; j < n; j++){
                    if(count[j]>(k+1)/2){
                        res += 1;
                    }
                }
                // out.println(res);
                ans = Math.min(ans, res);
                arr[n].clear();
                arr[f].add(t);
                arr[t].add(f);
            }
        }
        out.println(ans);
    }

    void f(int cur, int sum){
        seen[cur] = true;
        count[cur] = sum;
        for(int i : arr[cur]){
            if(seen[i]) continue;
            f(i,sum+1);
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
 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.