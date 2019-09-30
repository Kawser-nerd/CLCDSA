import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main{
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    int mod = 1_000_000_007;
    long inf = Long.MAX_VALUE;

    void solve(){
        int n = ni();
        long[] x = new long[n];
        long[] y = new long[n];
        List<long[]> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            x[i] = nl();
            y[i] = nl();
            list.add(new long[]{x[i], y[i], i});
        }
        double[] ans = new double[n];
        List<long[]> ch = convexHull(list);
        for(int i = 0; i < ch.size(); i++){
            long[] p = ch.get(i);
            long[] pre = ch.get((i-1+ch.size())%ch.size());
            long[] nex = ch.get((i+1+ch.size())%ch.size());
            long x1 = pre[0]-p[0];
            long y1 = pre[1]-p[1];
            long x2 = nex[0]-p[0];
            long y2 = nex[1]-p[1];
            double a = angle(x1,y1,x2,y2);
            ans[(int)p[2]] += (Math.PI - a) / (Math.PI * 2); 
        }
        for(int i = 0; i < n; i++){
            out.println(ans[i]);
        }
    } 

    public static List<long[]> convexHull(List<long[]> list){
        int k = 0;
        Collections.sort(list, new Comparator<long[]>(){
            @Override
            public int compare(long[] o1, long[] o2) {
                if(o1[0] != o2[0]) return Long.compare(o1[0], o2[0]);//o1[0]-o2[0];
                return Long.compare(o1[1], o2[1]);//o1[1]-o2[1];
            }
        });
        int n = list.size();
        long[][] qs = new long[n*2][2];
        for(int i=0; i<n; i++){
            while(k > 1 && cross(qs[k-2], qs[k-1], qs[k-1], list.get(i)) < 0) k--;
            qs[k++] = list.get(i);
        }
 
        for(int i=n-2, t=k; i>=0; i--){
            while(k > t && cross(qs[k-2], qs[k-1], qs[k-1], list.get(i)) < 0) k--;
            qs[k++] = list.get(i);
        }
 
        List<long[]> res = new ArrayList<>();
        for(int i=0; i<k-1; i++){
            res.add(qs[i]);
        }
        return res;
    }
 
    public static long cross(long[] p11, long[] p12, long[] p21, long[] p22){
        return (p12[0]-p11[0])*(p22[1]-p21[1]) - (p22[0]-p21[0])*(p12[1]-p11[1]);
    }
 
    double angle(double x1, double y1, double x2, double y2){
        double a1 = Math.atan2(y1, x1);
        double a2 = Math.atan2(y2, x2);
        double rad = Math.abs(a1-a2);
        if(rad>Math.PI) rad = 2*Math.PI - rad;
        return rad;
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