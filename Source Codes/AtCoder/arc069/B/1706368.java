import java.io.*;
import java.util.*;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";

    void solve()
    {
        int n = ni();
        char[] c = ns().toCharArray();
        int[] animal = new int[c.length];
        int last = 0;
        int first = 0;
        flag:
        for(int i = 0; i < 4; i++){
            if(i==0){
                animal[0] = 0;
                if(c[0] == 'o'){
                    animal[c.length-1] = 0;
                    animal[1] = 0;
                }
                else{
                    animal[c.length-1] = 0;
                    animal[1] = 1;
                }
            }
            if(i==1){
                animal[0] = 0;
                if(c[0] == 'o'){
                    animal[c.length-1] = 1;
                    animal[1] = 1;
                }
                else{
                    animal[c.length-1] = 1;
                    animal[1] = 0;
                }
            }
            if(i==2){
                animal[0] = 1;
                if(c[0] == 'o'){
                    animal[c.length-1] = 0;
                    animal[1] = 1;
                }
                else{
                    animal[c.length-1] = 0;
                    animal[1] = 0;
                }
            }
            if(i==3){
                animal[0] = 1;
                if(c[0] == 'o'){
                    animal[c.length-1] = 1;
                    animal[1] = 0;
                }
                else{
                    animal[c.length-1] = 1;
                    animal[1] = 1;
                }
            }
            first = animal[0];
            last = animal[c.length-1];
            for(int j = 1; j < c.length; j++){
                if(animal[j] == 0 && c[j] == 'o'){
                    animal[(j+1)%c.length] = animal[j-1];
                }
                if(animal[j] == 0 && c[j] == 'x'){
                    animal[(j+1)%c.length] = 1 - animal[j-1];
                }
                if(animal[j] == 1 && c[j] == 'o'){
                    animal[(j+1)%c.length] = 1 - animal[j-1];
                }
                if(animal[j] == 1 && c[j] == 'x'){
                    animal[(j+1)%c.length] = animal[j-1];
                }
                if(j==c.length-2){
                    if(animal[c.length-1] != last) continue flag;
                }
                if(j==c.length-1){
                    if(animal[0] != first) continue flag;
                }
            }
            for(int k = 0; k < c.length; k++){
                out.print(animal[k]==0 ? 'S' : 'W');
            }
            return;
        }
        out.println(-1);
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