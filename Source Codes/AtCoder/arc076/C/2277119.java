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

    int r; 
    int c;
    void solve(){
        r = ni();
        c = ni();
        int n = ni();

        int[][] line = new int[2*n][3];
        int p = 0;
        for(int i = 0; i < n; i++){
            int x1 = ni();
            int y1 = ni();
            int x2 = ni();
            int y2 = ni();
            if(!onedge(x1,y1)||!onedge(x2,y2)) continue;
            line[p] = new int[]{i+1, x1, y1};
            p++;
            line[p] = new int[]{i+1, x2, y2};
            p++;
        }
        Arrays.sort(line, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                int a_line = sel_edge(a[1],a[2]);
                int b_line = sel_edge(b[1],b[2]);
                if(a_line != b_line){
                    return  a_line-b_line;
                }
                if(a_line==0) return a[1]-b[1];
                if(a_line==1) return a[2]-b[2];
                if(a_line==2) return b[1]-a[1];
                if(a_line==3) return b[2]-a[2];
                return 0;
            }
        });

        int[] new_line = new int[2*n];
        for(int i = 0; i < 2*n; i++){
            new_line[i] = line[i][0];
        }
        out.println(parentheses_judge(2*n, new_line) ? "YES" : "NO");
    }

    boolean onedge(int x, int y){
        if(x==0||x==r||y==0||y==c) return true;
        else return false;
    }
    int sel_edge(int x, int y){
        if(y==0) return 0;
        if(x==r) return 1;
        if(y==c) return 2;
        if(x==0) return 3;
        return 0;
    }
    boolean parentheses_judge(int n, int[] list){
        Deque<Integer> st = new ArrayDeque<>();
        boolean[] seen = new boolean[n];
        for(int i = 0; i < n; i++){
            int cur = list[i];
            if(cur==0) continue;
            if(!seen[cur]){
                st.push(cur);
                seen[cur] = true;
                continue;
            }
            if(st.pop()!=cur) return false;
        }
        return true;
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