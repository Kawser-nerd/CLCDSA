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

    void solve(){
       int n = ni();
       int[][] x = new int[n][2];
       int[] f = new int[n];
       for(int i = 0; i < n; i++){
            x[i][0] = ni();
            x[i][1] = i+1;
            f[i] = x[i][0];
       }
       Arrays.sort(x, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0]-b[0];
            }
        });
       Deque<Integer> st = new ArrayDeque<>();
       for(int i = 0; i < n; i++){
            int res = x[i][1];
            for(int j = 0; j < res-1; j++){
                st.add(res);
            }
       }
       ArrayList<Integer> arr = new ArrayList<>();
       int prev = 1;
       for(int i = 0; i < n; i++){
            int cur = x[i][0];
            for(int j = prev; j < cur; j++){
                if(st.isEmpty()){
                    out.println("No");
                    return;
                }
                int tmp = st.pop();
                arr.add(tmp);
            }
            arr.add(x[i][1]);
            for(int j = 0; j < n-x[i][1]; j++){
                st.add(x[i][1]);
            }
            prev = cur+1;
       }
       while(!st.isEmpty()){
        int tmp = st.pop();
        arr.add(tmp);
       }
       int[] count = new int[n+1];
       int[] ans = new int[n+1];
       int c = 1;
       for(int i : arr){
        count[i]++;
        if(count[i]==i){
            ans[i] = c;
        }
        // out.println(i);
        c++;
       }
       for(int i = 1; i <= n; i++){
        if(ans[i]!=f[i-1]){
            out.println("No");
            return;
        }
        // out.println(ans[i]);
       }
       out.println("Yes");
       for(int i : arr){
        out.print(i+" ");
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