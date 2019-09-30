import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    // static int mod = 1_000_000_007;
    int mod = 998244353;
    long inf = Long.MAX_VALUE/2;

    int h;
    int w;
    char[][] map;
    boolean single = false;
    boolean single2 = false;
    int count = 0;

    void solve(){
        h = ni();
        w = ni();
        map = nm(h,w);
        if(h%2==1){
            h++;
            single = true;
        }
        if(w%2==1){
            single2 = true;
        }   
        boolean[] seen = new boolean[h];
        int[] res = new int[h];
        res[0] = 0;
        seen[0] = true;
        permute(1, res, seen);
        System.out.println("NO");
        // out.println(count);
    }

    void permute(int c, int[] res2, boolean[] seen){
        int[] res = new int[h];
        for(int i = 0; i < h; i++){
            res[i] = res2[i];
        }
        if(c==h-1){
            count++;
            for(int i = 0; i < h; i++){
                if(!seen[i]){
                    res[c] = i;
                    break;
                }
            }
            int v = -1;
            for(int i = 0; i < h; i++){
                if(single && res[i]==h-1){
                    res[i] = -1;
                    v = res[i-1];
                    // out.print("k ");
                }
                // out.print(res[i]+" ");
            }
            // out.println();
            // out.println(v);
            int t = single ? h-1 : h;
            int[] list = new int[t];
            int p = 0;
            for(int i = 0; i < h; i++){
                if(res[i]==v || res[i]==-1) continue;
                if(i%2==0) list[p/2] = res[i];
                else list[t-1-(p-1)/2] = res[i];
                p++;
                // out.println(p/2+" "+(t-1-(p-1)/2)+" "+res[i]);
            }
            if(single) list[p/2] = v;
            // for(int i : list){
            //     out.print(i+" ");
            // }
            // out.println();
            if(func(list)){
                System.out.println("YES");
                System.exit(0);
                return;
            }
        }
        if(c%2==0){
            for(int i = 0; i < h; i++){
                if(!seen[i]){
                    seen[i] = true;
                    res[c] = i;
                    permute(c+1, res, seen);
                    seen[i] = false;
                    break;
                }
            }
        }
        else{
            for(int i = 0; i < h; i++){
                if(!seen[i]){
                    seen[i] = true;
                    res[c] = i;
                    permute(c+1, res, seen);
                    seen[i] = false;
                }
            }
        }
    }

    boolean func(int[] list){
        boolean[] seen = new boolean[w];
        int x = 0;
        for(int i = 0; i < w; i++){
            if(seen[i]) continue;
            seen[i] = true;
            boolean flag = false;
            for(int j = i+1; j < w; j++){
                if(seen[j]) continue;
                flag = true;
                for(int k = 0; k < list.length; k++){
                    if(map[list[k]][i]!=map[list[list.length-1-k]][j]) flag = false;
                }
                if(flag){
                    seen[j] = true;
                    break;
                }
            }
            // if(flag) System.out.println("flag"+" "+i);
            // System.out.println("idx "+i);
            if(!flag) x++;
            // System.out.println(x);
            if(!single2&&x>0) return false;
            if(single2&&x>1) return false;
            // System.out.println(x);
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