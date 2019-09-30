import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Objects;
import java.util.StringTokenizer;
class Main{
	static int[] amida;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int D=sc.nextInt();
		amida=new int[N+1];
		for(int i=0; i<=N; i++) {
			amida[i]=i;
		}
		for(int i=0; i<M; i++) {
			swap(sc.nextInt());
		}
		int[] attri=new int[N+1];	//?????
		int[] amari=new int[N+1];
		Vertex[] chikan=new Vertex[N+1];
		for(int i=0; i<=N; i++) {
			attri[i]=-1;
			amari[i]=-1;
			chikan[i]=new Vertex();
		}
		int counter=0;
		int before=0;
		int now=0;
		for(int i=1; i<=N; i++) {
			if(attri[i]==-1) {
				attri[i]=counter;
				amari[i]=0;
				chikan[counter].add(i, i);
				before=i;
				now=amida[i];
				while(amari[now]==-1) {
					amari[now]=amari[before]+1;
					attri[now]=counter;
					chikan[counter].add(now,now);
					before=now;
					now=amida[before];
				}
				counter++;
			}
		}
		int[] goal=new int[N+1];
		for(int i=1; i<=N; i++) {
			int zokusei=attri[i];
			int vol=chikan[zokusei].size();
			int amr=amari[i];
			//pl(chikan[zokusei].getKey((amr+p)%vol));
			//pl(i+" attr"+attri[i]+" amari"+amari[i]);
			goal[chikan[zokusei].getKey((amr+D)%vol)]=i;
		}
		for(int i=1; i<=N; i++) {
			pl(goal[i]);
		}

	}
	static void swap(int i) {
		int a=amida[i];
		int b=amida[i+1];
		amida[i]=b;
		amida[i+1]=a;
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
		public static int getValue(Pair<Integer,Integer> a) {
			return a.value;
		}
		public static int getKey(Pair<Integer,Integer> a) {
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
		ArrayList <Pair<Integer,Integer>> rinsetu=new ArrayList<Pair<Integer,Integer>>();
		public void add(int V,int cost) {
			rinsetu.add(new Pair<Integer, Integer>(V,cost));
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
		public int getValue(int i) {
			return Pair.getValue(rinsetu.get(i));   //Value?????
		}
		public Pair<Integer,Integer> get(int i) {
			return rinsetu.get(i);   //Pair??????
		}
		public int getKey(int i) {
			return Pair.getKey(rinsetu.get(i)); //Value?????
		}
		public void changeKey(int i,int value) {	//???????????Key,Value??Key?????
			Pair<Integer,Integer> tmp=new Pair<Integer, Integer>(value,Pair.getValue(rinsetu.get(i)));
			rinsetu.set(i, tmp);
		}
		public void changeValue(int i,int value) {	//????????????Key,Value??Value?????
			Pair<Integer,Integer> tmp=new Pair<Integer, Integer>(Pair.getKey(rinsetu.get(i)),value);
			rinsetu.set(i, tmp);
		}
		public void changeKeyValue(int i,int key,int value) {	//????????????Key,Value?????
			Pair<Integer,Integer> tmp=new Pair<Integer, Integer>(key,value);
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