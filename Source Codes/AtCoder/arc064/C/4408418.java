import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;

public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		double x0 = sc.nextInt();
		double y0 = sc.nextInt();
		double xN1 = sc.nextInt();
		double yN1 = sc.nextInt();
		int N = sc.nextInt();
		double[] X= new double[N+2];
		double[] Y= new double[N+2];
		double[] R= new double[N+2];
		for(int i=1;i<=N;i++){
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		X[0] = x0;
		Y[0] = y0;
		X[N+1] = xN1;
		Y[N+1] = yN1;
		
		Graph G = new Graph(N+2);
		for(int i=0;i<N+2;i++){
			for(int j=0;j<N+2;j++){
				if(i!=j){
					double l = Math.max(0,Math.sqrt((X[i]-X[j]) * (X[i]-X[j]) + (Y[i]-Y[j]) * (Y[i]-Y[j])) - R[i] - R[j]);
					G.addWeightedEdge(i,j,l);
				}
			}
		}
		
		double[] L = G.dijkstra(0);
		System.out.println(L[N+1]);
	}
}


class Graph {
	ArrayList<Edge>[] list;
	int size;
	@SuppressWarnings("unchecked")
	Graph(int N){
		size = N;
		list = new ArrayList[N];
		for(int i=0;i<N;i++){
			list[i] = new ArrayList<Edge>();
		}
	}
	
	void addEdge(int a,int b){
		list[a].add(new Edge(b,1));
	}
	
	void addWeightedEdge(int a,int b, double c){
		list[a].add(new Edge(b,c));
	}
	
	void addEgdes(int[] a,int[] b){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],1));
		}
	}
	
	void addWeighterEdges(int[] a ,int[] b ,int[] c){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],c[1]));
		}
	}
	
	double[] bfs(int s){
		double[] L = new double[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		L[s] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);
		
		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				double c = e.cost;
				if(L[w]==-1){
					L[w] = L[v] + c;
					Q.add(w);
				}
			}
		}
		
		return L;
	}
	
	double[] dijkstra(int s){
		double[] L = new double[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] visited = new int[size];
		L[s] = 0;
		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(0,s));
		
		while(!Q.isEmpty()){
			
			Pair C = Q.poll();
			if(visited[(int)C.b]==0){
				L[(int)C.b] = C.a;
				visited[(int) C.b] = 1;
				for(Edge D:list[(int) C.b]){
					Q.add(new Pair(L[(int)C.b]+D.cost,D.to));
				}
			}
		}
		
		return L;
	}
}

class Edge{
	int to;
	double cost;
	
	Edge(int a,double b){
		to = a;
		cost = b;
	}
	
}

class Pair{
	double a;
	long b;
	
	Pair(double p,long q){
		this.a = p;
		this.b = q;
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

class SampleComparator implements Comparator<Pair>{
	public int compare(Pair P, Pair Q) {
		double temp = P.a-Q.a;
		if(temp==0){
			if(P.b>Q.b){
				return 1;
			}else{
				return -1;
			}
			
		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
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