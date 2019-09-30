import java.util.*;
import java.io.*;
public class Main {
class Node {
    int id;
    int sz;
    public Node(int id,int sz){
        this.id=id;
        this.sz=sz;
    }
}
    void solve(){
      int n=ni(),m=ni();
      arr=new int[n+1];
      sz=new int[n+1];
      hs=new HashSet[n+1];
      p=new int[n+1];
      for(int i=1;i<=n;i++) p[i]=ni();
      for(int i=1;i<=n;i++) {
          arr[i]=i;
          sz[i]=1;
          hs[i]=new HashSet<>();
          hs[i].add(p[i]);
      }
      while(m-->0){
          int x=ni(),y=ni();
          union(x,y);
      }
      int ans=0;
      for(int i=1;i<=n;i++){
          int root=root(i);
          if(hs[root].contains(i)) ans++;
      }
      pw.println(ans);
    }
    int arr[];
    int sz[];
    int p[];
    HashSet<Integer> hs[];
    int root(int a){
        while(arr[a]!=a){
            arr[a]=arr[arr[a]];
            a=arr[a];
        }
        return a;
    }
    boolean find(int a,int b){
        return root(a)==root(b);
    }
    void union(int a,int b){
        int rootA=root(a);
        int rootB=root(b);
        if(rootA==rootB) return;
        if(sz[rootA]<=sz[rootB]){
            arr[rootA]=rootB;
            sz[rootB]+=sz[rootA];
            hs[rootB].addAll(hs[rootA]);
            hs[rootA].clear();
        }else {
            arr[rootB]=rootA;
            sz[rootA]+=sz[rootB];
            hs[rootA].addAll(hs[rootB]);
            hs[rootB].clear();
        }
    }



    long M=(long)1e9+7;
    InputStream is;
    PrintWriter pw;
    String INPUT = "";
    void run() throws Exception {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        pw = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        pw.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }

    public static void main(String[] args) throws Exception { new Main().run(); }

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte() {
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

    private String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }

    private int[] na(int n) {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }

    private int ni() {
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

    private long nl() {
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

    private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.