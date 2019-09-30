import java.io.IOException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
 

 
public class Main{
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		@SuppressWarnings("unchecked")
		ArrayList<Edge>[] list = new ArrayList[N];
		for(int i=0;i<N;i++){
			list[i] = new ArrayList<Edge>();
		}
		for(int i=0;i<M;i++){
			int a = sc.nextInt() -1;
			int b = sc.nextInt() -1;
			long c = -sc.nextLong();
			Edge e = new Edge(b,c); 
			list[a].add(e);
			
		}
		long inf = 1000000000;
		inf *= inf;
		long[] dist = new long[N];
		dist[0] = 0;
		for(int i=1;i<N;i++){
			dist[i] = 1000000000;
			dist[i] *= dist[i];
		}
		for(int i=0;i<N-1;i++){
			for(int j=0;j<N;j++){
				for(Edge E:list[j]){
					if(dist[j]!=inf&&dist[E.to]>dist[j]+E.cost){
						dist[E.to]=dist[j]+E.cost;
					}
				}
			}
		}
		
		long ans = dist[N-1];
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(Edge E:list[j]){
					if(dist[j]!=inf&&dist[E.to]>dist[j]+E.cost){
						dist[E.to]=dist[j]+E.cost;
					}
				}
			}
		}
		if(dist[N-1]!=ans){
			System.out.println("inf");
		}else{
			System.out.println(-ans);
		}
	
	}
}

class Edge{
	int to;
	long cost;
	
	Edge(int a,long b){
		to = a;
		cost = b;
	}
	
}





class FastScanner {
    private final java.io.InputStream in = System.in;
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
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
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
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}