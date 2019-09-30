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
        int res[][] = new int[2*n][2];
        for(int i = 0; i < 2*n; i++) {
        	String[] s = ns().split(" ");
        	res[i][0] = s[0].equals("W") ? 0 : 1;
        	res[i][1] = Integer.parseInt(s[1])-1;
        }
        int[][] whiteupper = new int[2*n][n+1];
        int[][] blackupper = new int[2*n][n+1];
        for(int i = 0; i < 2*n; i++) {
        	for(int j = 0; j <= n; j++) {
        		if(i>0) whiteupper[i][j]=whiteupper[i-1][j];
        		if(i>0) blackupper[i][j]=blackupper[i-1][j];
        	}
        	if(res[i][0]==0) {
        		for(int j = 0; j <= res[i][1]; j++) {
        			whiteupper[i][j]++;
        		}
        	}
        	else {
        		for(int j = 0; j <= res[i][1]; j++) {
        			blackupper[i][j]++;
        		}
        	}
        }
        int[] wplace = new int[n];
        int[] bplace = new int[n];
        for(int i = 0; i < 2*n; i++) {
        	if(res[i][0]==0) wplace[res[i][1]] = i;
        	else bplace[res[i][1]] = i;
        }
        long[][] dp = new long[n+1][n+1];
        for(int i = 0; i <= n; i++) {
        	Arrays.fill(dp[i], inf);
        }
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
        	for(int j = 0; j <= n; j++) {
        		if(i>0) dp[i][j] = dp[i-1][j] + whiteupper[wplace[i-1]][i]+ 
        				blackupper[wplace[i-1]][j];
        		if(j>0) dp[i][j] = Math.min(dp[i][j], dp[i][j-1] + 
        				blackupper[bplace[j-1]][j]+
        				whiteupper[bplace[j-1]][i]);
        	}
        }
        out.println(dp[n][n]);
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