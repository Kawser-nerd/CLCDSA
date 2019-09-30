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
        int m = ni();
        boolean[][] exist = new boolean[n][n];
        for(int i = 0; i < m; i++){
            int f = ni()-1;
            int t = ni()-1;
            exist[f][t] = true;
            exist[t][f] = true;
        }
        ArrayList<Integer>[] edge = new ArrayList[n];
        for(int i = 0; i < n; i++){
            edge[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j||exist[i][j]) continue;
                edge[i].add(j);
            }
        }
        boolean[] seen = new boolean[n];
        int[] c = new int[n];
        Arrays.fill(c,-1);
        int[] num = new int[701];
        num[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(!edge[i].isEmpty()&&!seen[i]){
                Queue<int[]> q = new ArrayDeque<>();
                q.add(new int[]{i,0});
                seen[i] = true;
                int b = 0;
                int w = 0;
                while(!q.isEmpty()){
                    int[] r = q.poll();
                    c[r[0]] = r[1];
                    if(r[1]==0) b++;
                    else w++;
                    sum++;
                    for(int j : edge[r[0]]){
                        if(seen[j]){
                            if(c[j]==r[1]){
                                out.println(-1);
                                return;
                            }
                            continue;
                        }
                        q.add(new int[]{j,1-r[1]});
                        seen[j] = true;
                    }
                }
                int[] nnum = new int[701];
                for(int j = 0; j <= 700; j++){
                    if(num[j]==1){
                        nnum[j+b] = 1;
                        nnum[j+w] = 1;
                    }
                }
                for(int j = 0; j <= 700; j++){
                    num[j] = nnum[j];
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i <= n; i++){
            if(num[i]==1){
                int b1 = i;
                int w1 = sum-i;
                for(int j = 0; j <= n-sum; j++){
                    int b2 = b1 + j;
                    int w2 = w1 + n-sum - j;
                    int total = b2*(b2-1)/2 + w2*(w2-1)/2;
                    ans = Math.min(total,ans);
                }
            }
        }
        out.println(ans);
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