import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		Map<Integer,Map<Integer,Integer>>graph=new HashMap<>();
		for(int i=0;i<n-1;i++){
			int a=scanner.nextInt()-1;
			int b=scanner.nextInt()-1;
			int c=scanner.nextInt();
			if (graph.containsKey(a)) {
				graph.get(a).put(b,c);
			} else {
				Map<Integer,Integer>tmp=new HashMap<>();
				tmp.put(b,c);
				graph.put(a, tmp);
			}
			if (graph.containsKey(b)) {
				graph.get(b).put(a,c);
			} else {
				Map<Integer,Integer>tmp=new HashMap<>();
				tmp.put(a,c);
				graph.put(b, tmp);
			}
		}
		int q=scanner.nextInt();
		int k=scanner.nextInt()-1;
		int[] x=new int[q];
		int[] y=new int[q];
		for(int i=0;i<q;i++){
			x[i]=scanner.nextInt()-1;
			y[i]=scanner.nextInt()-1;
		}
		Deque<Integer>que=new ArrayDeque<>();
		que.add(k);
		Map<Integer,Long>costs=new HashMap<>();
		costs.put(k, 0l);
		Set<Integer>checked=new HashSet<>();
		while(!que.isEmpty()){
			int now=que.poll();
			checked.add(now);
			for(int next:graph.get(now).keySet()){
				if(checked.contains(next)){
					continue;
				}
				que.add(next);
				costs.put(next,costs.get(now)+graph.get(now).get(next));
			}
		}
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<q;i++){
			sb.append(costs.get(x[i])+costs.get(y[i])+"\n");
		}
		System.out.println(sb);
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