import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.NoSuchElementException;



public class Main{

	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M];
		int[] B = new int[M];
		for(int i=0;i<M;i++){
			A[i] = sc.nextInt()-1;
			B[i] = sc.nextInt()-1;
		}
		Graph G = new Graph(N);
		int[] used = new int[N];
		G.addEgdes(A,B);
		G.addEgdes(B,A);
		ArrayDeque<Integer> path = new ArrayDeque<Integer>();
		path.add(A[0]);
		path.add(B[0]);
		used[A[0]] = 1;
		used[B[0]] = 1;
		while(true){
			boolean b = false;
			for(int e:G.list[path.getLast()]){
				if(used[e]==0){
					b = true;
					path.addLast(e);
					used[e] = 1;
					break;
				}
			}
			if(!b){
				break;
			}
		}
		while(true){
			boolean b = false;
			for(int e:G.list[path.getFirst()]){
				if(used[e]==0){
					b = true;
					path.addFirst(e);
					used[e] = 1;
					break;
				}
			}
			if(!b){
				break;
			}
		}
		System.out.println(path.size());
		for(int v:path){
			System.out.print((v+1) + " ");
		}
	}
}

class Graph {
	ArrayList<Integer>[] list;
	
	@SuppressWarnings("unchecked")
	Graph(int N){
		list = new ArrayList[N];
		for(int i=0;i<N;i++){
			list[i] = new ArrayList<Integer>();
		}
	}
	
	void addEdge(int a,int b){
		list[a].add(b);
	}
	
	void addEgdes(int[] a,int[] b){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(b[i]);
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