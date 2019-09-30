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

    void solve(){
        int h = ni();
        int w = ni();
        char[][] map = nm(h,w);
        boolean[][] check = new boolean[h][w];
        int[] dx = new int[]{-1,-1,-1,0,0,0,1,1,1};
        int[] dy = new int[]{-1,0,1,-1,0,1,-1,0,1};
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j]=='.'){
                    for(int k = 0; k < 9; k++){
                        int cx = i + dx[k];
                        int cy = j + dy[k];
                        if(cx<0||cx>=h||cy<0||cy>=w) continue;
                        else{
                            check[cx][cy] = true;
                        }
                    }
                }
            }

        }
        boolean[][] ncheck = new boolean[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                ncheck[i][j] = true;
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!check[i][j]){
                    for(int k = 0; k < 9; k++){
                        int cx = i + dx[k];
                        int cy = j + dy[k];
                        if(cx<0||cx>=h||cy<0||cy>=w) continue;
                        else{
                            ncheck[cx][cy] = false;
                        }
                    }
                }
            }

        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(ncheck[i][j] && map[i][j]=='#'){
                    out.println("impossible");
                    return;
                }
                if(!ncheck[i][j] && map[i][j]=='.'){
                    out.println("impossible");
                    return;
                }
            }
        }
        out.println("possible");
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(check[i][j]) out.print(".");
                else out.print("#");
            }
            out.println();
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