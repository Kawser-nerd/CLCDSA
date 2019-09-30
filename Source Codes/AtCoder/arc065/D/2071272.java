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
        int m = ni();
        char[] c = ns().toCharArray();
        int[][] res = new int[m][2];
        for(int i = 0; i < m; i++){
            res[i][0] = ni()-1;
            res[i][1] = ni()-1;
        }
        char[] cmin = new char[n];
        char[] cmax = new char[n];
        for(int i = 0; i < n; i++){
            cmin[i] = c[i];
            cmax[i] = c[i];
        }
        for(int i = 0; i < m; i++){
            int left = res[i][0];
            int right = res[i][1];
            int zero = 0;
            int one = 0;
            for(int j = left; j <= right; j++){
                if(cmin[j]=='0') zero++;
                else one++;
            }
            for(int j = left; j <= right; j++){
                if(j<left+one) cmin[j] = '1';
                else cmin[j] = '0';
            }
        }
        for(int i = 0; i < m; i++){
            int left = res[i][0];
            int right = res[i][1];
            int zero = 0;
            int one = 0;
            for(int j = left; j <= right; j++){
                if(cmax[j]=='0') zero++;
                else one++;
            }
            for(int j = left; j <= right; j++){
                if(j<left+zero) cmax[j] = '0';
                else cmax[j] = '1';
            }
        }
        int[] zeromin = new int[n];
        int[] zeromax = new int[n];
        for(int i = 0; i < n; i++){
            if(cmin[i]=='0') zeromin[i]++;
            if(cmax[i]=='0') zeromax[i]++;
        }
        for(int i = 1; i < n; i++){
            zeromin[i] += zeromin[i-1];
            zeromax[i] += zeromax[i-1];
        }
        Arrays.sort(res, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            }
        });
        boolean[] l = new boolean[n];
        HashMap<Integer, Integer> map = new HashMap<>();
        int min = 0;
        for(int i = 0; i < m; i++){
            if(res[i][1]>min){
                map.put(res[i][0], res[i][1]);
                min = res[i][1];
                l[res[i][0]] = true;
            }
        }
        long[] dp = new long[n+1];
        dp[0] = 1;
        boolean flag = false;
        int target = n;
        for(int i = 0; i < n; i++){
            long[] ndp = new long[n+2];
            if(l[i]){
                flag = true;
                target = map.get(i);
                // ????????
                for(int k = 0; k <= n; k++){
                    if(i>0){
                        if(k<zeromin[i-1]||k>zeromax[i-1]) dp[k] = 0;
                    }
                }
            }
            for(int j = 0; j <= n; j++){
                if(!flag){
                    if(c[i]=='0' && dp[j]>0) ndp[j+1] = dp[j];
                    if(c[i]=='1' && dp[j]>0) ndp[j] = dp[j];
                    ndp[j+1]%=mod;
                    ndp[j]%=mod;
                }else{
                    if(dp[j]>0){
                        ndp[j] += dp[j];
                        ndp[j+1] += dp[j];
                        ndp[j]%=mod;
                        ndp[j+1]%=mod;
                    }
                }
            }
            if(i==target){
                flag = false;
                // ????????
                for(int k = 0; k <= n; k++){
                    if(k<zeromin[i]||k>zeromax[i]) ndp[k] = 0;
                }
            }
            for(int j = 0; j <= n; j++) dp[j] = ndp[j];
            // for(int j = 0; j < n; j++){
            //     out.print(dp[j]+" ");
            // }
            // out.println();
        }
        // for(int i = 0; i < n; i++){
        //     out.println(dp[i]);
        // }
        out.println(dp[zeromin[n-1]]);
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