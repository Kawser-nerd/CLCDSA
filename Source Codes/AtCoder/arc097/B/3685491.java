import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{

	static int N;
	static int M;
	static int[] p;
	static int[] root;
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		
		N = sc.nextInt();
		M = sc.nextInt();
		
		p = new int[N+1];
		int[] q = new int[N+1];
		root = new int[N+1];
		for(int i=1;i<=N;i++){
			p[i] = sc.nextInt();
			root[i] = i;
			q[p[i]] = i;
		}
		for(int i=0;i<M;i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			unite(x,y);
		}
		int ans = 0;
		for(int i=1;i<=N;i++){
			if(same(i,q[i])){
				ans++;
			}
		}
		
		System.out.println(ans);
	}
	private static boolean same(int i, int j) {
		if(find(i)==find(j)){
			return true;
		}
		return false;
	}
	private static void unite(int x, int y) {
		if(find(x)==find(y)){
			return;
		}else{
			root[find(y)] = find(x);
		}
		
	}
	private static int find(int x) {
		if(root[x]==x){
			return x;
		}
		return root[x] = find(root[x]);
		
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