import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {
	
    public static void main(String[] args) {
	FastScanner sc = new FastScanner();
	
    int N = 10;
    char[][] A;
    
    A = new char[N][];
    for (int i = 0; i < N; i++) {
        A[i] = sc.next().toCharArray();
    }
    
    int count = 0;
    
    //?????
    for(int i =0; i<N; i++){
    	for(int j =0; j<N; j++){
    		if(A[i][j] == 'o'){
    			count += 1;
    		}
    	}
    }
    
    boolean can = false;
    
    class Node{
    	int a,b;
    	
    	public Node(int a, int b){
    		this.a = a;
    		this.b = b;
    	}
    	
    	@Override
    	public boolean equals(Object o){
    		if(o instanceof Node){
    			Node p = (Node) o;
    			return a==p.a && b==p.b;
    		}
    		return super.equals(o);
    	}
    }
    
    //??
    for(int i =0; i<N; i++){
    	for(int j =0; j<N; j++){
    		
    		if(A[i][j] == 'o'){
    			continue;
    		}
    		
    		Deque<Node> stack = new ArrayDeque<Node>();
    		ArrayList<Node> visited = new ArrayList<Node>();
    		
    		Node start = new Node(i,j);
    		stack.offerLast(start);
    		visited.add(start);

    		
    		while(!stack.isEmpty()){
    			Node last = stack.pollLast();
    			
    			if(last.a!=0){
    				Node ix = new Node(last.a-1,last.b);
    				if(A[ix.a][ix.b] == 'o' && !visited.contains(ix)){
        				stack.offerLast(ix);
        				visited.add(ix);
    				}
    			}
    			
    			if(last.a!=9){
    				Node ix = new Node(last.a+1,last.b);
    				if(A[ix.a][ix.b] == 'o' && !visited.contains(ix)){
        				stack.offerLast(ix);
        				visited.add(ix);
    				}
    			}

    			if(last.b!=0){
    				Node ix = new Node(last.a,last.b-1);
    				if(A[ix.a][ix.b] == 'o' && !visited.contains(ix)){
        				stack.offerLast(ix);
        				visited.add(ix);
    				}
    			}
    			

    			if(last.b!=9){
    				Node ix = new Node(last.a,last.b+1);
    				if(A[ix.a][ix.b] == 'o' && !visited.contains(ix)){
        				stack.offerLast(ix);
        				visited.add(ix);
    				}
    			}
    			
    		}
    		
    		if(visited.size() == count+1){
    			can = true;
    			break;
    		}
    		
    		
    	}
    }
    	if(can){
        	System.out.println("YES");
    	}
    	else{
    		System.out.println("NO");
    	}
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