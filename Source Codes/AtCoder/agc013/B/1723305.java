import java.io.*;
import java.util.*;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";

    int MOD = 1000000007;
    int INF = 10000000;

    List<Integer>[] al;
    boolean[] seen;
    ArrayList<Integer> ansl;
    ArrayList<Integer> ansr;
    void solve()
    {
        int n = ni();
        int m = ni();

        al = new List[n];
        seen = new boolean[n];
        for(int i = 0; i < n; i++){
            al[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int f = ni()-1;
            int t = ni()-1;
            al[f].add(t);
            al[t].add(f);
        }
        int l = 0;
        int r = al[0].get(0);
        seen[l] = true;
        seen[r] = true;
        ansl = new ArrayList<>();
        ansr = new ArrayList<>();
        while(true){
            int prevl = l;
            int prevr = r;
            for(int x : al[l]){
                if(!seen[x]){
                    ansl.add(x);
                    seen[x] = true;
                    l = x;
                    break;
                }
            }
            for(int y : al[r]){
                if(!seen[y]){
                    ansr.add(y);
                    seen[y] = true;
                    r = y;
                    break;
                }
            }
            if(prevl == l && prevr == r) break;
        }
        out.println(ansr.size()+ansl.size()+2);
        for(int i = 0; i < ansl.size(); i++){
            out.print((ansl.get(ansl.size()-i-1)+1)+" ");
        }
        out.print(1+" ");
        out.print((al[0].get(0)+1)+" ");
        for(int i = 0; i < ansr.size(); i++){
            out.print((ansr.get(i)+1)+" ");
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