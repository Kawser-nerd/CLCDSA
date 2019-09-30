import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		Vertex[] G=new Vertex[N+1];
		for(int i=0; i<=N; i++) {
			G[i]=new Vertex();
		}
		for(int i=0; i<N-1; i++) {
			int f=sc.nextInt();
			int t=sc.nextInt();
			int c=sc.nextInt();
			G[f].add(t, c);
			G[t].add(f, c);
		}
		int Q=sc.nextInt();
		int K=sc.nextInt();
		PriorityQueue<Pair<Integer,Long>> que = new PriorityQueue<Pair<Integer,Long>>(Comparator.comparing(v -> v.value));
		long[] dist=new long[N+1];
		long INF=1145141919810364L;
		Arrays.fill(dist, INF);
		dist[K]=0L;
		que.add(new Pair<Integer,Long>(K,0L));
		Pair<Integer,Long> tmp=new Pair<Integer,Long>(0,0L);
		while(!que.isEmpty()) {
			tmp=que.poll();
			int vertex=Pair.getKey(tmp);
			if(dist[vertex]<Pair.getValue(tmp)) {
				continue;
			}
			else {
				for(int i=0; i<G[vertex].size(); i++) {
					tmp=G[vertex].get(i);
					int to=Pair.getKey(tmp);
					long cost=Pair.getValue(tmp);
					if(dist[to]>dist[vertex]+cost) {
						dist[to]=dist[vertex]+cost;
						tmp=new Pair<Integer,Long>(to,dist[to]);
						que.add(tmp);
					}
				}
			}
		}
		for(int i=0; i<Q; i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			pl(dist[x]+dist[y]);
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
	public static final class Pair<K, V>{        //powered by mikit
		//Pair<?????????>???????????????Pair<Integer,Long>???????
		public K key;
		public V value;
		public Pair(K  key, V value) {
			this.key = key;
			this.value = value;
		}
		public static long getValue(Pair<Integer,Long> a) {
			return a.value;
		}
		public static int getKey(Pair<Integer,Long> a) {
			return a.key;
		}
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			Pair<?, ?> pair = (Pair<?, ?>) o;
			return Objects.equals(key, pair.key) &&
					Objects.equals(value, pair.value);
		}
		public int hashCode() {
			return Objects.hash(key, value);
		}
	}
	public static class Vertex{
		ArrayList <Pair<Integer,Long>> rinsetu=new ArrayList<Pair<Integer,Long>>();
		public void add(int V,long cost) {
			rinsetu.add(new Pair<Integer, Long>(V,cost));
		}
		public void show() {        //????????
			for(int i=0; i<rinsetu.size(); i++) {
				System.out.println(rinsetu.get(i));
			}
		}
		public void sort_by_cost() {        //??????????????
			rinsetu.sort(Comparator.comparing(p -> p.value));
		}
		public void sort_by_Vertex() {      //????????????????
			rinsetu.sort(Comparator.comparing(p -> p.key));
		}
		public long getValue(int i) {
			return Pair.getValue(rinsetu.get(i));   //Value?????
		}
		public Pair<Integer,Long> get(int i) {
			return rinsetu.get(i);   //Pair??????
		}
		public int getKey(int i) {
			return Pair.getKey(rinsetu.get(i)); //Value?????
		}
		public void changeKey(int i,int value) {	//???????????Key,Value??Key?????
			Pair<Integer,Long> tmp=new Pair<Integer, Long>(value,Pair.getValue(rinsetu.get(i)));
			rinsetu.set(i, tmp);
		}
		public void changeValue(int i,long value) {	//????????????Key,Value??Value?????
			Pair<Integer,Long> tmp=new Pair<Integer, Long>(Pair.getKey(rinsetu.get(i)),value);
			rinsetu.set(i, tmp);
		}
		public void changeKeyValue(int i,int key,long value) {	//????????????Key,Value?????
			Pair<Integer,Long> tmp=new Pair<Integer, Long>(key,value);
			rinsetu.set(i, tmp);
		}
		public int size() {     //?????
			return rinsetu.size();
		}
		public int find_Vertex(int a) {     //??????????????????  ?????????????
			for(int i=0; i<rinsetu.size(); i++) {
				if(a==Pair.getKey(rinsetu.get(i))) {
					return i;
				}
			}
			return -1;
		}
	}
}