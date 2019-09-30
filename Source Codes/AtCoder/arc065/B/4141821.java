import java.io.IOException;
import java.util.HashMap;
import java.util.NoSuchElementException;

public class Main{
	
	static int[] UF1par;
	static int[] UF2par;
	static int[] UF1rank;
	static int[] UF2rank;
	
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc= new FastScanner();
		int N = sc.nextInt();
		int K = sc.nextInt();
		int L = sc.nextInt();
		long n = N;
		UF1par = new int[N];
		UF2par = new int[N];
		UF1rank = new int[N];
		UF2rank = new int[N];
		
		for(int i=0;i<N;i++){
			UF1par[i] = i;
			UF2par[i] = i;
		}
		for(int i=0;i<K;i++){
			int p = sc.nextInt();
			int q = sc.nextInt();
			p--;
			q--;
			unite1(p,q);
		}
		for(int i=0;i<L;i++){
			int r = sc.nextInt();
			int s = sc.nextInt();
			r--;
			s--;
			unite2(r,s);

		}
		
		HashMap<Long,Integer> num = new HashMap<Long,Integer>();
		long[] l = new long[N];
		for(int i=1;i<=N;i++){
			long j = find1(i-1);
			long k = find2(i-1);
			l[i-1] = j * n + k;
			
			if(num.containsKey(l[i-1])){
				num.put(l[i-1], num.get(l[i-1])+1);
			}else{
				num.put(l[i-1], 1);
			}
			
			
		}
		for(int i=1;i<=N;i++){
			System.out.print(num.get(l[i-1]) + " ");
		}
		
	}


	private static void unite1(int p, int q) {
		p = find1(p);
		q = find1(q);
		if(p==q){
			return;
			
		}else{
			if(UF1rank[p]<UF1rank[q]){
				
				UF1par[p] = q;
			}else{
				UF1par[q] = p;
				if(UF1rank[p]==UF1rank[q]){
					
					UF1rank[p]++;
				}
			}
		}
	}


	private static int find1(int p) {
		if(UF1par[p]==p){
			return p;
		}else{
			
			return UF1par[p] =find1(UF1par[p]);
		}
	}
	
	private static void unite2(int p, int q) {
		p = find2(p);
		q = find2(q);
		if(p==q){
			return;
			
		}else{
			if(UF2rank[p]<UF2rank[q]){
				
				UF2par[p] = q;
			}else{
				UF2par[q] = p;
				if(UF2rank[p]==UF2rank[q]){
					
					UF2rank[p]++;
				}
			}
		}
	}


	private static int find2(int p) {
		if(UF2par[p]==p){
			return p;
		}else{
			return UF2par[p] = find2(UF2par[p]);
			
		}
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