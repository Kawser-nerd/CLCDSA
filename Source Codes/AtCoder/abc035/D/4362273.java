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

public class Main{
	static int N,M;
	static long T;
	static long[] dist1;
	static long[] dist2;
	static long[] getmoney;
	static long INF=1000000007;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		T=sc.nextInt();
		getmoney=new long[N];
		dist1=new long[N];
		dist2=new long[N];
		Vertex[] graph1=new Vertex[N];
		Vertex[] graph2=new Vertex[N];
		for(int i=0; i<N; i++) {
			graph1[i]=new Vertex();
			graph2[i]=new Vertex();
		}
		for(int i=0; i<N; i++) {
			getmoney[i]=sc.nextInt();
		}
		for(int i=0; i<M; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			long c=sc.nextLong();
			graph1[f].add(t,c);
			graph2[t].add(f,c);
		}
		PriorityQueue<Pair<Long,Long>> Q1 = new PriorityQueue<Pair<Long,Long>>(Comparator.comparing(v -> v.value));
		PriorityQueue<Pair<Long,Long>> Q2 = new PriorityQueue<Pair<Long,Long>>(Comparator.comparing(v -> v.value));
		Arrays.fill(dist1, INF);
		Arrays.fill(dist2, INF);
		dist1[0]=0;
		dist2[0]=0;
		Pair<Long,Long> start=new Pair<Long,Long>(0L,0L);
		Q1.add(start);
		Q2.add(start);
		Pair<Long,Long> tmp=new Pair<Long,Long>(0L,0L);
		while(!Q1.isEmpty()) {
			tmp=Q1.poll();
			long vertex=Pair.getKey(tmp);
			if(dist1[(int)vertex]<Pair.getValue(tmp)) {
				continue;
			}
			else {
				for(int i=0; i<graph1[(int)vertex].size(); i++) {
					tmp=graph1[(int)vertex].get(i);
					int to=(int)Pair.getKey(tmp);
					int cost=(int)Pair.getValue(tmp);
					if(dist1[to]>dist1[(int)vertex]+cost) {
						dist1[to]=dist1[(int)vertex]+cost;
						tmp=new Pair<Long,Long>((long)to,dist1[to]);
						Q1.add(tmp);
					}
				}
			}
		}

		while(!Q2.isEmpty()) {
			tmp=Q2.poll();
			long vertex=Pair.getKey(tmp);
			if(dist2[(int)vertex]<Pair.getValue(tmp)) {
				continue;
			}
			else {
				for(int i=0; i<graph2[(int)vertex].size(); i++) {
					tmp=graph2[(int)vertex].get(i);
					long to=Pair.getKey(tmp);
					long cost=Pair.getValue(tmp);
					if(dist2[(int)to]>dist2[(int)vertex]+cost) {
						dist2[(int)to]=dist2[(int)vertex]+cost;
						tmp=new Pair<Long,Long>(to,dist2[(int)to]);
						Q2.add(tmp);
					}
				}
			}
		}
		long max=0;
		for(int i=0; i<N; i++) {
			max=Math.max(max,(T-dist1[i]-dist2[i])*getmoney[i]);
		}
		pl(max);
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
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	public static final class Pair<K, V>{        //powered by mikit
		//Pair<?????????>???????????????Pair<Integer,Integer>???????
		public K key;
		public V value;
		public Pair(K key, V value) {
			this.key = key;
			this.value = value;
		}
		public static long getValue(Pair<Long,Long> a) {
			return a.value;
		}
		public static long getKey(Pair<Long,Long> a) {
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
		public String toString() {
			return "Pair{" +
					"x=" + key +
					", y=" + value +
					'}';
		}
	}
	public static class Vertex{
		ArrayList <Pair<Long,Long>> rinsetu;
		public Vertex() {
			this.rinsetu=new ArrayList<Pair<Long,Long>>();
		}
		public void add(long V,long cost) {
			rinsetu.add(new Pair<Long,Long>(V,cost));
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
		public Pair<Long,Long> get(int i) {
			return rinsetu.get(i);   //Pair??????
		}
		public long getKey(int i) {
			return Pair.getKey(rinsetu.get(i)); //Value?????
		}
		public void changeKey(int i ,long value) {	//???????????Key,Value??Key?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(value,Pair.getValue(rinsetu.get(i)));
			rinsetu.set(i, tmp);
		}
		public void changeValue(int i,long value) {	//????????????Key,Value??Value?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(Pair.getKey(rinsetu.get(i)),value);
			rinsetu.set(i, tmp);
		}
		public void changeKeyValue(int i,long key,long value) {	//????????????Key,Value?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(key,value);
			rinsetu.set(i, tmp);
		}
		public int size() {     //?????
			return rinsetu.size();
		}
		public int find_Vertex(long a) {     //??????????????????  ?????????????
			for(int i=0; i<rinsetu.size(); i++) {
				if(a==Pair.getKey(rinsetu.get(i))) {
					return i;
				}
			}
			return -1;
		}
	}
}

/*

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

public class ABC035D {
	static int N,M,T;
	static long[] dist1;
	static long[] dist2;
	static long[] getmoney;
	static long INF=1000000007;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		T=sc.nextInt();
		getmoney=new long[N];
		dist1=new long[N];
		dist2=new long[N];
		Vertex[] graph1=new Vertex[N];
		Vertex[] graph2=new Vertex[N];
		for(int i=0; i<N; i++) {
			graph1[i]=new Vertex();
			graph2[i]=new Vertex();
		}
		for(int i=0; i<N; i++) {
			getmoney[i]=sc.nextInt();
		}
		for(int i=0; i<M; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			long c=sc.nextLong();
			graph1[f].add(t,c);
			graph2[t].add(f,c);
		}
		PriorityQueue<Pair<Long,Long>> Q1 = new PriorityQueue<Pair<Long,Long>>(Comparator.comparing(v -> v.value));
		PriorityQueue<Pair<Long,Long>> Q2 = new PriorityQueue<Pair<Long,Long>>(Comparator.comparing(v -> v.value));
		Arrays.fill(dist1, INF);
		Arrays.fill(dist2, INF);
		dist1[0]=0;
		dist2[0]=0;
		Pair<Long,Long> start=new Pair<Long,Long>(0L,0L);
		Q1.add(start);
		Q2.add(start);
		Pair<Long,Long> tmp=new Pair<Long,Long>(0L,0L);
		while(!Q1.isEmpty()) {
			tmp=Q1.poll();
			long vertex=Pair.getKey(tmp);
			if(dist1[(int)vertex]<Pair.getValue(tmp)) {
				continue;
			}
			else {
				for(int i=0; i<graph1[(int)vertex].size(); i++) {
					tmp=graph1[(int)vertex].get(i);
					int to=(int)Pair.getKey(tmp);
					int cost=(int)Pair.getValue(tmp);
					if(dist1[to]>dist1[(int)vertex]+cost) {
						dist1[to]=dist1[(int)vertex]+cost;
						tmp=new Pair<Long,Long>((long)to,dist1[to]);
						Q1.add(tmp);
					}
				}
			}
		}

		while(!Q2.isEmpty()) {
			tmp=Q2.poll();
			long vertex=Pair.getKey(tmp);
			if(dist2[(int)vertex]<Pair.getValue(tmp)) {
				continue;
			}
			else {
				for(int i=0; i<graph2[(int)vertex].size(); i++) {
					tmp=graph2[(int)vertex].get(i);
					long to=Pair.getKey(tmp);
					long cost=Pair.getValue(tmp);
					if(dist2[(int)to]>dist2[(int)vertex]+cost) {
						dist2[(int)to]=dist2[(int)vertex]+cost;
						tmp=new Pair<Long,Long>(to,dist2[(int)to]);
						Q2.add(tmp);
					}
				}
			}
		}
		long max=0;
		for(int i=0; i<N; i++) {
			if(dist1[i]+dist2[i]>T) {
				pl(dist1[i]+dist2[i]);
				continue;
			}
			else {
				max=Math.max(max,(T-dist1[i]-dist2[i])*getmoney[i]);
			}
		}
		pl(max);
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
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	public static final class Pair<K, V>{        //powered by mikit
		//Pair<?????????>???????????????Pair<Integer,Integer>???????
		public K key;
		public V value;
		public Pair(K key, V value) {
			this.key = key;
			this.value = value;
		}
		public static long getValue(Pair<Long,Long> a) {
			return a.value;
		}
		public static long getKey(Pair<Long,Long> a) {
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
		public String toString() {
			return "Pair{" +
					"x=" + key +
					", y=" + value +
					'}';
		}
	}
	public static class Vertex{
		ArrayList <Pair<Long,Long>> rinsetu;
		public Vertex() {
			this.rinsetu=new ArrayList<Pair<Long,Long>>();
		}
		public void add(long V,long cost) {
			rinsetu.add(new Pair<Long,Long>(V,cost));
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
		public Pair<Long,Long> get(int i) {
			return rinsetu.get(i);   //Pair??????
		}
		public long getKey(int i) {
			return Pair.getKey(rinsetu.get(i)); //Value?????
		}
		public void changeKey(int i ,long value) {	//???????????Key,Value??Key?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(value,Pair.getValue(rinsetu.get(i)));
			rinsetu.set(i, tmp);
		}
		public void changeValue(int i,long value) {	//????????????Key,Value??Value?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(Pair.getKey(rinsetu.get(i)),value);
			rinsetu.set(i, tmp);
		}
		public void changeKeyValue(int i,long key,long value) {	//????????????Key,Value?????
			Pair<Long,Long> tmp=new Pair<Long,Long>(key,value);
			rinsetu.set(i, tmp);
		}
		public int size() {     //?????
			return rinsetu.size();
		}
		public int find_Vertex(long a) {     //??????????????????  ?????????????
			for(int i=0; i<rinsetu.size(); i++) {
				if(a==Pair.getKey(rinsetu.get(i))) {
					return i;
				}
			}
			return -1;
		}
	}
}

*/