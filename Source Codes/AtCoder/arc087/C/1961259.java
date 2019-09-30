import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE/2;

    long ans = 0;
    void solve(){
        int n = ni();
        long l = nl();
        TrieByLink trie = new TrieByLink();
        for(int i = 0;i < n;i++){
            trie.add(ns().toCharArray());
        }
        // int[] g = new int[21];
        // for(int i = 1; i <= 20; i++){
        //     HashSet<Integer> set = new HashSet<>();
        //     int a = 0;
        //     set.add(a);
        //     for(int j = i-1; j >= 1; j--){
        //         a ^= g[j];
        //         set.add(a);
        //     }
        //     while(set.contains(g[i])) g[i]++;
        // }
        // for(int i = 0; i <= 20; i++){
        //     out.println(g[i]);
        // }
        dfs(trie.root, 0, l);
        out.println(ans!=0 ? "Alice" : "Bob");

    }

    void dfs(TrieByLink.Node cur, int depth, long l){
        if(cur.firstChild!=null){
            if(cur.firstChild.next==null){
                ans ^= (l-depth)&-(l-depth);
            }
            for(TrieByLink.Node nex = cur.firstChild; nex != null; nex = nex.next){
                dfs(nex, depth+1, l);
            }
        }
    }  


    public static class TrieByLink {
        public Node root = new Node((char)0, 0);
        public int gen = 1;
        public static final char[] atoz = "abcdefghijklmnopqrstuvwxyz".toCharArray();
        
        public static class Node
        {
            public int id;
            public char c;
            public Node next, firstChild;
            public int hit = 0;
            
            public Node fail;
            
            public Node(char c, int id)
            {
                this.id = id;
                this.c = c;
            }
            
            public String toString(String indent)
            {
                StringBuilder sb = new StringBuilder();
                sb.append(indent + id + ":" + c);
                if(hit != 0)sb.append(" H:" + hit);
                if(fail != null)sb.append(" F:" + fail.id);
                sb.append("\n");
                for(Node c = firstChild;c != null; c = c.next){
                    sb.append(c.toString(indent + "  "));
                }
                return sb.toString();
            }
        }
        
        public void add(char[] s)
        {
            Node cur = root;
            Node pre = null;
            for(char c : s){
                pre = cur; cur = cur.firstChild;
                if(cur == null){
                    cur = pre.firstChild = new Node(c, gen++);
                }else{
                    for(;cur != null && cur.c != c;pre = cur, cur = cur.next);
                    if(cur == null)cur = pre.next = new Node(c, gen++);
                }
            }
            cur.hit++;
        }
        
        public void buildFailure()
        {
            root.fail = null;
            Queue<Node> q = new ArrayDeque<Node>();
            q.add(root);
            while(!q.isEmpty()){
                Node cur = q.poll();
                inner:
                for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                    q.add(ch);
                    for(Node to = cur.fail; to != null; to = to.fail){
                        for(Node lch = to.firstChild;lch != null; lch = lch.next){
                            if(lch.c == ch.c){
                                ch.fail = lch;
                                ch.hit += lch.hit; // propagation of hit
                                continue inner;
                            }
                        }
                    }
                    ch.fail = root;
                }
            }
        }
        
        public Node next(Node cur, char c)
        {
            for(;cur != null;cur = cur.fail){
                for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                    if(ch.c == c)return ch;
                }
            }
            return root;
        }
        
        public int[][] ngMatrix(char[] cs)
        {
            int[] map = new int[128];
            Arrays.fill(map, -1);
            for(int i = 0;i < cs.length;i++)map[cs[i]] = i;
            
            int[][] a = new int[gen+1][gen+1];
            Node[] nodes = toArray();
            for(int i = 0;i < gen;i++){
                if(nodes[i].hit > 0)continue;
                int nohit = cs.length;
                boolean[] ved = new boolean[cs.length];
                for(Node cur = nodes[i];cur != null;cur = cur.fail){
                    for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                        if(map[ch.c] >= 0 && !ved[map[ch.c]]){
                            ved[map[ch.c]] = true;
                            if(ch.hit == 0)a[ch.id][i]++;
                            nohit--;
                        }
                    }
                }
                a[0][i] += nohit;
            }
            Arrays.fill(a[gen], 1);
            return a;
        }
        
        public int[][] okMatrix(char[] cs)
        {
            int[] map = new int[128];
            Arrays.fill(map, -1);
            for(int i = 0;i < cs.length;i++)map[cs[i]] = i;
            
            int[][] a = new int[gen+1][gen+1];
            Node[] nodes = toArray();
            for(int i = 0;i < gen;i++){
                if(nodes[i].hit > 0)continue;
                int nohit = cs.length;
                boolean[] ved = new boolean[cs.length];
                for(Node cur = nodes[i];cur != null;cur = cur.fail){
                    for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                        if(map[ch.c] >= 0 && !ved[map[ch.c]]){
                            ved[map[ch.c]] = true;
                            if(ch.hit > 0){
                                a[gen][i]++;
                            }else{
                                a[ch.id][i]++;
                            }
                            nohit--;
                        }
                    }
                }
                a[0][i] += nohit;
            }
            a[gen][gen]++;
            return a;
        }
        
        public void search(char[] q)
        {
            Node cur = root;
            outer:
            for(char c : q){
                for(;cur != null;cur = cur.fail){
                    for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                        if(ch.c == c){
                            // ch.hit
                            cur = ch;
                            continue outer;
                        }
                    }
                }
                cur = root;
            }
        }
        
        public int countHit(char[] q)
        {
            Node cur = root;
            int hit = 0;
            outer:
            for(char c : q){
                for(;cur != null;cur = cur.fail){
                    for(Node ch = cur.firstChild;ch != null; ch = ch.next){
                        if(ch.c == c){
                            hit += ch.hit; // add hit
                            cur = ch;
                            continue outer;
                        }
                    }
                }
                cur = root;
            }
            return hit;
        }
        
        public Node[] toArray()
        {
            Node[] ret = new Node[gen];
            ret[0] = root;
            for(int i = 0;i < gen;i++){
                Node cur = ret[i];
                if(cur.next != null)ret[cur.next.id] = cur.next;
                if(cur.firstChild != null)ret[cur.firstChild.id] = cur.firstChild;
            }
            return ret;
        }
        
        public String toString()
        {
            return root.toString("");
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