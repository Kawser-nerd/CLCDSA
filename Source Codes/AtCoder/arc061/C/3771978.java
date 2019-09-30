import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Objects;
 

 
public class Main{
	
	ArrayList<Integer>[] list;
	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] p = new int[M];
		int[] q = new int[M];
		int[] c = new int[M];
		
		HashMap<Pair,Integer> map = new HashMap<Pair,Integer>();
		
		int pos = N;
		
	
		
		for(int i=0;i<M;i++){
			p[i] = sc.nextInt()-1;
			q[i] = sc.nextInt()-1;
			c[i] = sc.nextInt();
			Pair P = new  Pair(p[i],c[i]);
			Pair Q = new  Pair(q[i],c[i]);
			
			if(!map.containsKey(P)){
				map.put(P,pos);
				pos++;
			}
			if(!map.containsKey(Q)){
				map.put(Q,pos);
				pos++;
			}
			
			
		}
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[] list = new ArrayList[pos];
		for(int i=0;i<pos;i++){
			list[i] = new ArrayList<Integer>();
		}
		int[] visit = new int[pos];
		for(int i=0;i<pos;i++){
			visit[i] = -1;
		}
		int[] checked = new int[pos];
		for(int i=0;i<M;i++){
			Pair P = new  Pair(p[i],c[i]);
			Pair Q = new  Pair(q[i],c[i]);
			list[map.get(P)].add(map.get(Q));
			list[map.get(Q)].add(map.get(P));
		}
		
		for(Pair P:map.keySet()){
			list[P.a].add(map.get(P));
			list[map.get(P)].add(P.a);
		}
		
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(0);
		visit[0] = 0;
		
		while(!Q.isEmpty()){
			int g = Q.poll();
			if(checked[g]==0){
			
			for(int h:list[g]){
				if(visit[h]==-1){
					if(g<N){
						visit[h] = visit[g] + 1;
						Q.add(h);
					}else{
						visit[h] = visit[g];
						Q.push(h);
						
					}

					
				}else if(visit[h]==visit[g]+1&&g>=N){
					visit[h] = visit[g];
					
					Q.push(h);
				}

					
				
			}
			}
			checked[g] = 1;

		}
		System.out.println(visit[N-1]);
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
}