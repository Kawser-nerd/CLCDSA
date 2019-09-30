import java.util.*;
import java.io.*;

public class Main {

    static int[] L;
    static int[] R;
    static int[] D;
    static boolean judge = true;

    static class Node {
        ArrayList<Edge> list = new ArrayList<>();
        boolean det = false;
        int cost    = 0;
    }

    static class Edge {
        int src;
        int dst;
        int cost;
        Edge(int s, int d, int c) {
            src = s;
            dst = d;
            cost = c;
        }
    }
    static Node[] node;

    static void dfs(int id, boolean[] vis) {
        if(vis[id]) return;
        vis[id] = true;
        Node n = node[id];
        for(int i = 0; i < n.list.size(); i++) {
            int nex = n.list.get(i).dst;
            if(node[nex].det) {
                if(node[nex].cost != n.cost+ n.list.get(i).cost) judge = false;
            } else {
                node[nex].det = true;
                node[nex].cost = n.list.get(i).cost + n.cost;
                if(vis[nex]) continue;
                dfs(nex,vis);
            }
        }
    }
    
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        int M = sc.nextInt();

        L = new int[M];
        R = new int[M];
        D = new int[M];
        for(int i = 0; i < M; i++) {
            L[i] = sc.nextInt() - 1;
            R[i] = sc.nextInt() - 1;
            D[i] = sc.nextInt();
        }

        boolean[] vis = new boolean[N];
        node   = new Node[N];
        for(int i = 0; i < N; i++) {
            node[i] = new Node();
        }
        for(int i = 0; i < M; i++) {
            node[R[i]].list.add(new Edge(R[i],L[i],D[i]));
            node[L[i]].list.add(new Edge(L[i],R[i],-D[i]));
        }

        for(int i = 0; i < N; i++) {
            if(vis[i]) continue;
            node[i].det = true;
            dfs(i,vis);
        }

        if(judge) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }


    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        if (!hasNext()) throw new NoSuchElementException();
        int n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}