import java.io.IOException;
import java.util.ArrayList;
import java.util.NoSuchElementException;



public class Main{
	static int[][] visited;
	static int[][] length;
	static ArrayList<Integer>[] list;
	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		visited = new int[N][2];
		length = new int[N][2];

		int F = 0;
		int S = 0;
		list = new ArrayList[N];
		for(int i=0;i<N;i++) {
			list[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<N-1;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			list[a].add(b);
			list[b].add(a);
		}
		
		search(0,0,0);
		search(N-1,0,1);
		
		for(int i=0;i<N;i++) {
			if(length[i][0]<=length[i][1]) {
				F++;
			}else {
				S++;
			}
		}

		if(F>S) {
			System.out.println("Fennec");
		}else {
			System.out.println("Snuke");
		}
	}
	private static void search(int i, int j, int k) {
		if(visited[i][k]==1) {
			return;
		}else {
			visited[i][k] = 1;
			length[i][k]=j;
			for(int p:list[i]) {
				search(p,j+1,k);
			}
			
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.