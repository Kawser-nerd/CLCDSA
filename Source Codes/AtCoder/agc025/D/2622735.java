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
        int d1 = ni();
        int d2 = ni();
        int[][] map = colorMap(d1, n);
        // for(int i = 0; i < 2*n; i++){
        //     for(int j = 0; j < 2*n; j++){
        //         out.print(map[i][j]+" ");
        //     }
        //     out.println();
        // }
        int[][] map2 = colorMap(d2, n);
        int[][] map3 = new int[2*n][2*n];
        int[] num = new int[4];
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < 2*n; j++){
                map3[i][j] = map[i][j] + 2*map2[i][j];
                num[map3[i][j]]++;
            }
        }
        int id = 0;
        int max = 0;
        for(int i = 0; i < 4; i++){
            if(num[i]>max){
                max = num[i];
                id = i;
            }
        }
        int p = 0;
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < 2*n; j++){
                if(map3[i][j]==id&&p<n*n){
                    out.println(i+" "+j);
                    p++;
                }
            }
        }
    }

    int[][] colorMap(int d1, int n){
        int[][] map = new int[2*n][2*n];
        boolean[] sqrt = new boolean[10*n*n];
        for(int i = 0; i <= 3*n; i++){
            sqrt[i*i] = true;
        }
        ArrayList<int[]>[] edge = new ArrayList[4*n*n];
        for(int i = 0; i < 4*n*n; i++){
            edge[i] = new ArrayList<>();
        }
        ArrayList<int[]> list = new ArrayList<>();
        for(int k = 0; k <= 2*n; k++){
            int dist = d1-k*k;
            if(dist>=0&&sqrt[dist]){
                int d = (int)Math.sqrt(dist);
                list.add(new int[]{k,d});
                if(d!=0)list.add(new int[]{k,-d});
                if(k!=0)list.add(new int[]{-k,d});
                if(k!=0||d!=0)list.add(new int[]{-k,-d});
            }
        }
        int count = 0;
        long start = System.currentTimeMillis();
        boolean[][] seen = new boolean[2*n][2*n];
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < 2*n; j++){
                if(seen[i][j]) continue;
                Deque<int[]> que = new ArrayDeque<>();
                que.add(new int[]{i,j,0});
                while(!que.isEmpty()){
                    int[] cur = que.poll();
                    seen[cur[0]][cur[1]] = true;
                    map[cur[0]][cur[1]] = cur[2];
                    for(int[] res : list){
                        int ci = cur[0]+res[0];
                        int cj = cur[1]+res[1];
                        if(ci<0||ci>=2*n||cj<0||cj>=2*n) continue;
                        if(seen[ci][cj]) continue;
                        que.add(new int[]{ci,cj,1-cur[2]});
                        seen[ci][cj] = true;

                    }
                }
            }
        }
        return map;
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