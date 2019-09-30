import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    int mod = 1_000_000_007;
    long inf = Long.MAX_VALUE;

    void solve(){
        int n = ni();
        int[][] left_sorted = new int[n][3];
        int[][] right_sorted = new int[n][3];
        for(int i = 0; i < n; i++){
            int left = ni();
            int right = ni();
            left_sorted[i][0] = left;
            left_sorted[i][1] = right;
            left_sorted[i][2] = i;
            right_sorted[i][0] = left;
            right_sorted[i][1] = right;
            right_sorted[i][2] = i;
        }
        Arrays.sort(left_sorted, (a,b)->b[0]-a[0]);
        Arrays.sort(right_sorted, (a,b)->a[1]-b[1]);
        boolean[] seen = new boolean[n];
        int flag = 0;
        long prev = 0;
        long ans = 0;
        int lid = 0;
        int rid = 0;
        for(int i = 0; i < 10*n; i++){
            if(flag==0){
                if(lid>=n) continue;
                if(seen[left_sorted[lid][2]]){
                    lid++;
                    continue;
                }
                seen[left_sorted[lid][2]] = true;
                if(left_sorted[lid][0]<=prev) break;
                ans += Math.abs(left_sorted[lid][0]-prev);
                prev = left_sorted[lid][0];
                lid++;
            }
            if(flag==1){
                if(rid>=n) continue;
                if(seen[right_sorted[rid][2]]){
                    rid++;
                    continue;
                }
                seen[right_sorted[rid][2]] = true;
                if(right_sorted[rid][1]>=prev) break;
                ans += Math.abs(right_sorted[rid][1]-prev);
                prev = right_sorted[rid][1];
                rid++;
            }
            flag = 1-flag;
            // out.println(prev+" "+ans);
        }
        ans += Math.abs(prev);
        long ans2 = 0;
        prev = 0;
        flag = 1;
        lid = 0;
        rid = 0;
        seen = new boolean[n];
        for(int i = 0; i < 10*n; i++){
            if(flag==0){
                if(lid>=n) continue;
                if(seen[left_sorted[lid][2]]){
                    lid++;
                    continue;
                }
                seen[left_sorted[lid][2]] = true;
                if(left_sorted[lid][0]<=prev) break;
                ans2 += Math.abs(left_sorted[lid][0]-prev);
                prev = left_sorted[lid][0];
                lid++;
            }
            if(flag==1){
                if(rid>=n) continue;
                if(seen[right_sorted[rid][2]]){
                    rid++;
                    continue;
                }
                seen[right_sorted[rid][2]] = true;
                if(right_sorted[rid][1]>=prev) break;
                ans2 += Math.abs(right_sorted[rid][1]-prev);
                prev = right_sorted[rid][1];
                rid++;
            }
            flag = 1-flag;
            // out.println(prev+" "+ans);
        }
        ans2 += Math.abs(prev);
        out.println(Math.max(ans,ans2));
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