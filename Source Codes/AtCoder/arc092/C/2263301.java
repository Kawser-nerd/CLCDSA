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
        long[] a = new long[n];
        for(int i = 0; i < n; i++){
            a[i] = nl();
        }
        long ans = -inf;
        long sum = 0;
        int[][] idx = new int[n][n];
        int id = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                if(j==i){
                    idx[j][i] = 1;
                    sum += a[j];
                }
                else if((j-i)%2==0 && a[j]>=0){
                    idx[j][i] = 1;
                    sum += a[j];
                }
            }
            if(sum>ans){
                ans = sum;
                id = i;
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(idx[i][id]==1){
                list.add(i-prev);
                prev = i+1;
            }
        }
        list.add(n-prev);
        ArrayList<Integer> exe = new ArrayList<>();
        int cur = 1;
        int length = n;
        for(int i = 0; i < list.size(); i++){
            if(i==0){
                for(int j = 0; j < list.get(i); j++){
                    exe.add(cur);
                    length--;
                }
            }
            else if(i==list.size()-1){
                for(int j = 0; j < list.get(i); j++){
                    exe.add(length);
                    length--;
                }
            }
            else{
                int nokori = list.get(i);
                while(nokori>0){
                    if(nokori>1){
                        exe.add(cur+2);
                        nokori-=2;
                        length-=2;
                    }
                    if(nokori==1){
                        exe.add(cur+1);
                        nokori--;
                        length-=2;
                    }
                }
            }
        }
        out.println(ans);
        out.println(exe.size());
        for(int i : exe){
            out.println(i);
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