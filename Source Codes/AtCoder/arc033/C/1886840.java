import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE;

    void solve()
    {
        Node root = null;
        for(int Q = ni();Q > 0;Q--){
            int t = ni();
            int x = ni();
            if(t == 1){
                Node y = new Node(x);
                root = insertb(root, y);
            }else if(t == 2){
                Node tar = get(root, x-1);
                out.println(tar.v+tar.add);
                root = erase(root, x-1);
            }
        }
    }
    
    public static Random gen = new Random();
    
    static public class Node
    {
        public long v; // value
        public long priority;
        public Node left, right, parent;
        
        public int count;
        
        public long add; // add cover
        
        public Node(int v)
        {
            this.v = v;
            priority = gen.nextLong();
            update(this);
        }
        
        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append("Node [v=");
            builder.append(v);
            builder.append(", count=");
            builder.append(count);
            builder.append(", parent=");
            builder.append(parent != null ? parent.v : "null");
            builder.append(", add=");
            builder.append(add);
            builder.append("]");
            return builder.toString();
        }
    }

    public static Node update(Node a)
    {
        if(a == null)return null;
        a.count = 1;
        if(a.left != null)a.count += a.left.count;
        if(a.right != null)a.count += a.right.count;
        
        return a;
    }
    
    public static Node disconnect(Node a)
    {
        if(a == null)return null;
        a.left = a.right = a.parent = null;
        return update(a);
    }
    
    public static Node root(Node x)
    {
        if(x == null)return null;
        while(x.parent != null)x = x.parent;
        return x;
    }
    
    public static int count(Node a)
    {
        return a == null ? 0 : a.count;
    }
    
    public static void setParent(Node a, Node par)
    {
        if(a != null)a.parent = par;
    }
    
    public static void add(Node a, int L, int R, int V)
    {
        if(a == null || L >= R || L >= count(a) || R <= 0)return;
        if(L <= 0 && R >= count(a)){
            a.v += V;
            a.add += V;
        }else{
            add(a.left, L, R, V);
            add(a.right, L-count(a.left)-1, R-count(a.left)-1, V);
            if(L <= count(a.left) && count(a.left) < R)a.v += V;
        }
        update(a);
    }
    
    public static void fall(Node a)
    {
        if(a == null)return;
        if(a.left != null){
            a.left.add += a.add;
            a.left.v += a.add;
            update(a.left);
        }
        if(a.right != null){
            a.right.add += a.add;
            a.right.v += a.add;
            update(a.right);
        }
        a.add = 0;
        update(a);
    }
    
    public static Node merge(Node a, Node b)
    {
        if(b == null)return a;
        if(a == null)return b;
        if(a.priority > b.priority){
            fall(a);
            setParent(a.right, null);
            setParent(b, null);
            a.right = merge(a.right, b);
            setParent(a.right, a);
            return update(a);
        }else{
            fall(b);
            setParent(a, null);
            setParent(b.left, null);
            b.left = merge(a, b.left);
            setParent(b.left, b);
            return update(b);
        }
    }
    
    // [0,K),[K,N)
    public static Node[] split(Node a, int K)
    {
        if(a == null)return new Node[]{null, null};
        fall(a);
        if(K <= count(a.left)){
            setParent(a.left, null);
            Node[] s = split(a.left, K);
            a.left = s[1];
            setParent(a.left, a);
            s[1] = update(a);
            return s;
        }else{
            setParent(a.right, null);
            Node[] s = split(a.right, K-count(a.left)-1);
            a.right = s[0];
            setParent(a.right, a);
            s[0] = update(a);
            return s;
        }
    }
    
    public static Node insert(Node a, int K, Node b)
    {
        if(a == null)return b;
        fall(a);
        if(b.priority < a.priority){
            if(K <= count(a.left)){
                a.left = insert(a.left, K, b);
                setParent(a.left, a);
            }else{
                a.right = insert(a.right, K-count(a.left)-1, b);
                setParent(a.right, a);
            }
            return update(a);
        }else{
            Node[] ch = split(a, K);
            b.left = ch[0]; b.right = ch[1];
            setParent(b.left, b);
            setParent(b.right, b);
            return update(b);
        }
    }
    
    // delete K-th
    public static Node erase(Node a, int K)
    {
        if(a == null)return null;
        if(K < count(a.left)){
            a.left = erase(a.left, K);
            setParent(a.left, a);
            return update(a);
        }else if(K == count(a.left)){
            fall(a);
            setParent(a.left, null);
            setParent(a.right, null);
            Node aa = merge(a.left, a.right);
            disconnect(a);
            return aa;
        }else{
            a.right = erase(a.right, K-count(a.left)-1);
            setParent(a.right, a);
            return update(a);
        }
    }
    
    public static Node get(Node a, int K)
    {
        while(a != null){
            fall(a);
            if(K < count(a.left)){
                a = a.left;
            }else if(K == count(a.left)){
                break;
            }else{
                K = K - count(a.left)-1;
                a = a.right;
            }
        }
        return a;
    }
    
    static Node[] Q = new Node[100];
    public static Node update(Node a, int K, int v)
    {
        int p = 0;
        while(a != null){
            Q[p++] = a;
            if(K < count(a.left)){
                a = a.left;
            }else if(K == count(a.left)){
                break;
            }else{
                K = K - count(a.left)-1;
                a = a.right;
            }
        }
        a.v = v;
        while(p > 0){
            update(Q[--p]);
        }
        return a;
    }
    
    public static int index(Node a)
    {
        if(a == null)return -1;
        int ind = count(a.left);
        while(a != null){
            Node par = a.parent;
            if(par != null && par.right == a){
                ind += count(par.left) + 1;
            }
            a = par;
        }
        return ind;
    }
    
    public static Node[] nodes(Node a) { return nodes(a, new Node[count(a)], 0, count(a)); }
    public static Node[] nodes(Node a, Node[] ns, int L, int R)
    {
        if(a == null)return ns;
        nodes(a.left, ns, L, L+count(a.left));
        ns[L+count(a.left)] = a;
        nodes(a.right, ns, R-count(a.right), R);
        return ns;
    }
    
    public static Node insertb(Node root, Node x)
    {
        int ind = lowerBound(root, x.v);
        return insert(root, ind, x);
    }
    
    public static int lowerBound(Node a, long q)
    {
        int lcount = 0;
        while(a != null){
            fall(a);
            if(a.v >= q){
                a = a.left;
            }else{
                lcount += count(a.left) + 1;
                a = a.right;
            }
        }
        return lcount;
    }
    
    
    public static String toString(Node a, String indent)
    {
        if(a == null)return "";
        StringBuilder sb = new StringBuilder();
        sb.append(toString(a.left, indent + "  "));
        sb.append(indent).append(a).append("\n");
        sb.append(toString(a.right, indent + "  "));
        return sb.toString();
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