import java.util.*;
import java.io.*;

public class Main{
    static ArrayList<ArrayList<Integer[]>> graph;
    static HashMap<Long, Integer> idMap;
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        int m = sc.nextInt();
        graph = new ArrayList<ArrayList<Integer[]>>();
        idMap = new HashMap<Long, Integer>();
        if(m == 0){
            System.out.println(-1);
            return;
        }
        for(int i=0; i<m; i++){
            int p = sc.nextInt()-1;
            int q = sc.nextInt()-1;
            int c = sc.nextInt()-1;
            int pId = getId(p, c);
            int qId = getId(q, c);
            graph.get(pId).add(new Integer[]{qId, 0});
            graph.get(qId).add(new Integer[]{pId, 0});
        }
        getId(0, -1);
        getId(n-1, -1);
        

        PriorityQueue<Integer[]> que = new PriorityQueue<Integer[]>(new java.util.Comparator<Integer[]>() {
            public int compare(Integer[] i1, Integer[] i2){
                return i1[1] - i2[1];
            }
        });
        int[] len = new int[idMap.size()];
        Arrays.fill(len, -1);
        len[getId(0, -1)] = 0;
        que.add(new Integer[]{getId(0, -1), 0});
        while(!que.isEmpty()){
            Integer[] current = que.poll();
            for(Integer[] next : graph.get(current[0])){
                int nextLen = len[current[0]] + next[1];
                if(len[next[0]] > nextLen || len[next[0]] == -1){
                    que.add(new Integer[]{next[0], nextLen});
                    len[next[0]] = nextLen;
                }
            }
        }

        System.out.println(len[getId(n-1, -1)]);
    }

    public static int getId(long station, long company){
        long tmpId = company * 10000000 + station;
        int id;
        if(!idMap.containsKey(tmpId)){
            idMap.put(tmpId, id = idMap.size());
            graph.add(new ArrayList<Integer[]>());
            graph.get(id).add(new Integer[]{getId(station, -1), 0});
            graph.get(getId(station, -1)).add(new Integer[]{id, 1});
        }else{
            id = idMap.get(tmpId);
        }
        return id;
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
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
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
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}