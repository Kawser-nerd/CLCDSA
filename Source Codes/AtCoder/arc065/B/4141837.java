import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.NoSuchElementException;

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc= new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int L = sc.nextInt();
		long n = N;
		
		UnionFindTree UF1 = new UnionFindTree(N);
		UnionFindTree UF2 = new UnionFindTree(N);
		
		for(int i=0;i<K;i++){
			int p = sc.nextInt()-1;
			int q = sc.nextInt()-1;

			UF1.unite(p,q);
		}
		for(int i=0;i<L;i++){
			int r = sc.nextInt()-1;
			int s = sc.nextInt()-1;

			UF2.unite(r,s);

		}
		
		HashMap<Long,Integer> num = new HashMap<Long,Integer>();
		long[] l = new long[N];
		for(int i=1;i<=N;i++){
			long j = UF1.find(i-1);
			long k = UF2.find(i-1);
			l[i-1] = j * n + k;
			
			if(num.containsKey(l[i-1])){
				num.put(l[i-1], num.get(l[i-1])+1);
			}else{
				num.put(l[i-1], 1);
			}
			
			
		}
		for(int i=1;i<=N;i++){
			out.print(num.get(l[i-1]) + " ");
		}
		out.flush();
	}


	
	
}

class UnionFindTree {
	int[] root;
	int[] rank;
	
	UnionFindTree(int N){
		root = new int[N];
		rank = new int[N];
		for(int i=0;i<N;i++){
			root[i] = i;
		}
	}
	
	public int find(int x){
		if(root[x]==x){
			return x;
		}else{
			return find(root[x]);
		}
	}
	
	public void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y){
			return;
		}else{
			if(rank[x]<rank[y]){
				root[x] = y;
			}else{
				root[y] = x;
				if(rank[x]==rank[y]){
					rank[x]++;
				}
			}
		}
	}
	
	public boolean same(int x,int y){
		return find(x)==find(y);
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