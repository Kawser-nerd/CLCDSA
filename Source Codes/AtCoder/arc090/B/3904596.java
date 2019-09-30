import java.io.IOException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Objects;



public class Main{
	static int[] root;
	static ArrayList<Pair>[] list;
	static long[] pos;
	static int[] visited;
	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		pos =  new long[N];
		int[] L = new int[M];
		int[] R = new int[M];
		int[] D = new int[M];
		root = new int[N];
		visited = new int[N];
		list = new ArrayList[N];
		for(int i=0;i<N;i++) {
			root[i] = -1;
			list[i] = new ArrayList<Pair>();

		}
		
		for(int i=0;i<M;i++) {
			int l = sc.nextInt()-1;
			int r = sc.nextInt()-1;
			int d = sc.nextInt();
			if(l>r) {
				L[i] = r;
				R[i] = l;
				D[i] = -d;
			}else {
				L[i] = l;
				R[i] = r;
				D[i] = d;
			}
			
			unit(L[i],R[i]);
			list[L[i]].add(new Pair(R[i],D[i]));
			list[R[i]].add(new Pair(L[i],-D[i]));
			
		}
		
		for(int i=0;i<N;i++) {
			dfs(i);
		}
		
		for(int i=0;i<M;i++) {
			if(pos[L[i]]+D[i]!=pos[R[i]]) {
				if(root[L[i]]==root[R[i]]) {
					System.out.println("No");
					return;
				}
				
			}
		}

		System.out.println("Yes");
	
	
	
	}
	private static void dfs(int i) {
		if(visited[i]==0) {
			visited[i] = 1;
			for(Pair P:list[i]) {
				pos[P.a] = pos[i] + P.b;
				dfs(P.a);
			}
		}
		
	}
	private static void unit(int i, int j) {
		if(find(i)!=find(j)) {
			root[find(i)] = root[find(j)];
		}
	}
	private static int find(int j) {
		if(root[j] == -1) {
			return j;
		}else {
			return root[j] = find(root[j]);
		}
	}	
}

class Pair {
	int a;
	int b;
 
	Pair(int p,int q){
		a = p;
		b = q;
	}
	
	public boolean equals(Object o){
		Pair O = (Pair) o;
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}
		
		
	}
	
	public int hashCode(){
		return Objects.hash(a,b);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.