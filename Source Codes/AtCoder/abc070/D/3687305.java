import java.util.Map.Entry;
import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		ArrayList<ArrayList<Pair>> edgeList = new ArrayList<>();
		for(int i = 0; i < N; i++) edgeList.add(new ArrayList<Pair>());
		for(int i = 0; i < N - 1; i++){
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			edgeList.get(a).add(new Pair(b, c));
			edgeList.get(b).add(new Pair(a, c));
		}
		int Q = sc.nextInt();
		int K = sc.nextInt() - 1;
		
		long[] cost = new long[N];
		Arrays.fill(cost, Long.MAX_VALUE);
		cost[K] = 0;
		ArrayList<Pair> queue = new ArrayList<>();
		queue.add(new Pair(K, 0));
		while(!queue.isEmpty()){
			Pair q = queue.remove(0);
			for(Pair p : edgeList.get(q.vertex)){
				if(q.cost + p.cost < cost[p.vertex]){
					queue.add(new Pair(p.vertex, q.cost + p.cost));
					cost[p.vertex] = q.cost + p.cost;
				}
			}
		}
		
		//for(long c : cost) System.out.print(c + " ");
		for(int i = 0; i < Q; i++){
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			System.out.println(cost[x] + cost[y]);
		}
	}
}

class Pair{
	int vertex;
	long cost;
	public Pair(int v, long c){
		vertex = v;
		cost = c;
	}
}

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
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
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
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
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}