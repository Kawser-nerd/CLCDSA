import java.util.Map.Entry;
import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] c = new int[10][10];
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				c[i][j] = sc.nextInt();
		int[] before = new int[10];
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++){
				int A = sc.nextInt();
				if(A != -1) before[A]++;
			}
		
		long ans = 0;
		for(int i = 0; i <= 9; i++){
			if(i == 1 || before[i] == 0) continue;
			int start = i;
			int goal = 1;
			long[] visited = new long[10];
			Arrays.fill(visited, Long.MAX_VALUE);
			visited[start] = 0;
			
			ArrayList<Pair> queue = new ArrayList<>();
			queue.add(new Pair(start, 0));
			while(!queue.isEmpty()){
				Pair p = queue.remove(0);
				for(int j = 0; j <= 9; j++){
					if(j == p.vertex) continue;
					if(c[p.vertex][j] + p.cost < visited[j]){
						queue.add(new Pair(j, c[p.vertex][j] + p.cost));
						visited[j] = c[p.vertex][j] + p.cost;
					}
				}
			}
			//for(long v : visited) System.out.print(v + " ");
			//System.out.println();
			ans += visited[1] * before[i];
		}
		System.out.println(ans);
	}
	
}

class Pair{
	int vertex;
	int cost;
	public Pair(int v, int c){
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