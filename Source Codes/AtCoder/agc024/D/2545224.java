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
        ArrayList<Integer>[] edge = new ArrayList[n];
        int[][] e = new int[n-1][2];
        for(int i = 0; i < n; i++) edge[i] = new ArrayList<Integer>();
        for(int i = 0; i < n-1; i++){
            int from = ni()-1;
            int to = ni()-1;
            edge[from].add(to);
            edge[to].add(from);
            e[i][0] = from;
            e[i][1] = to;
        }
        int col = n;
        long[] le = new long[n+1];
        Arrays.fill(le,inf);
        for(int i = 0; i < n; i++){
            boolean[] seen = new boolean[n];
            Deque<int[]> q = new ArrayDeque<>();
            q.add(new int[]{i, 0});
            int[] leaf = new int[n+1];
            int cmax = 0;
            while(!q.isEmpty()){
                int[] res = q.pop();
                cmax = Math.max(cmax, res[1]+1);
                seen[res[0]] = true;
                int p = 0;
                for(int j : edge[res[0]]){
                    if(!seen[j]){
                        q.add(new int[]{j, res[1]+1});
                        p++;
                    }
                }
                leaf[res[1]] = Math.max(leaf[res[1]], p);
            }
            long lt = 1;
            for(int j = 0; j < n; j++){
                if(leaf[j]==0) break;
                lt *= leaf[j];
            }
            le[cmax] = Math.min(le[cmax], lt);
            col = Math.min(cmax, col);
        }
        for(int i = 0; i < n-1; i++){
            boolean[] seen = new boolean[n];
            Deque<int[]> q = new ArrayDeque<>();
            q.add(new int[]{e[i][0], 0});
            q.add(new int[]{e[i][1], 0});
            seen[e[i][0]] = true;
            seen[e[i][1]] = true;
            int[] leaf = new int[n+1];
            int cmax = 0;
            while(!q.isEmpty()){
                int[] res = q.pop();
                cmax = Math.max(cmax, res[1]+1);
                seen[res[0]] = true;
                int p = 0;
                for(int j : edge[res[0]]){
                    if(!seen[j]){
                        q.add(new int[]{j, res[1]+1});
                        p++;
                    }
                }
                leaf[res[1]] = Math.max(leaf[res[1]], p);
            }
            long lt = 2;
            for(int j = 0; j < n; j++){
                if(leaf[j]==0) break;
                lt *= leaf[j];
            }
            le[cmax] = Math.min(le[cmax], lt);
            col = Math.min(cmax, col);
        }
        out.println(col+" "+le[col]);
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