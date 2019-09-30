import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Objects;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int Ma=sc.nextInt();
		int Mb=sc.nextInt();
		//?????????????
		//????3??DP??
		int[][][] dp=new int[41][401][401];
		int INF=1000000007;
		for(int i=0; i<=40; i++) {
			for(int j=0; j<=400; j++) {
				Arrays.fill(dp[i][j],INF);
			}
		}
		dp[0][0][0]=0;
		int[][] kusuri=new int[N][3];
		for(int i=0; i<N; i++) {
			kusuri[i][0]=sc.nextInt();
			kusuri[i][1]=sc.nextInt();
			kusuri[i][2]=sc.nextInt();
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<=400; j++) {
				for(int k=0; k<=400; k++) {
					if(dp[i][j][k]<INF) {
						dp[i+1][j][k]=Math.min(dp[i+1][j][k],dp[i][j][k]);
						dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]]=Math.min(dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]],dp[i][j][k]+kusuri[i][2]);
						//pl(i+1+" "+j+" "+k+" "+dp[i+1][j][k]);
						//pl(i+1+" "+(j+kusuri[i][0])+" "+(k+kusuri[i][1])+" "+dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]]);
					}
				}
			}
		}
		int min=114514810;
		int counter=1;
		while(Ma*counter<=400 && Mb*counter<=400) {
			min=Math.min(dp[N][Ma*counter][Mb*counter],min);
			counter++;
		}
		if(min==114514810) {
			pl(-1);
		}
		else {
			pl(min);
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
	public static final class Triple<K, V1, V2> {
		public K key;
		public V1 value1;
		public V2 value2;

		public Triple(K key, V1 value1, V2 value2) {
			this.key = key;
			this.value1 = value1;
			this.value2 = value2;
		}
		public static int getValue(Triple<Integer,Integer,Integer> a) {
			return a.value1;
		}
		public static int getKey(Triple<Integer,Integer,Integer> a) {
			return a.key;
		}
		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			Triple<?, ?, ?> triple = (Triple<?, ?, ?>) o;
			return Objects.equals(key, triple.key) &&
					Objects.equals(value1, triple.value1) &&
					Objects.equals(value2, triple.value2);
		}

		@Override
		public int hashCode() {
			return Objects.hash(key, value1, value2);
		}

		@Override
		public String toString() {
			return "Triple{" +
					"x=" + key +
					", y1=" + value1 +
					", y2=" + value2 +
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


/*import java.util.Arrays;
import java.util.Scanner;

class D54{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int Ma=sc.nextInt();
		int Mb=sc.nextInt();
		int[][][] dp=new int[41][401][401];
		int INF=1000000007;
		for(int i=0; i<=40; i++) {
			for(int j=0; j<=400; j++) {
				Arrays.fill(dp[i][j],INF);
			}
		}
		dp[0][0][0]=0;
		int[][] kusuri=new int[N][3];
		for(int i=0; i<N; i++) {
			kusuri[i][0]=sc.nextInt();
			kusuri[i][1]=sc.nextInt();
			kusuri[i][2]=sc.nextInt();
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<=400; j++) {
				for(int k=0; k<=400; k++) {
					if(dp[i][j][k]<INF) {
						dp[i+1][j][k]=Math.min(dp[i+1][j][k],dp[i][j][k]);
						dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]]=Math.min(dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]],dp[i][j][k]+kusuri[i][2]);
					}
				}
			}
		}
		int min=114514810;
		int counter=1;
		while(Ma*counter<=400 && Mb*counter<=400) {
			min=Math.min(dp[N][Ma*counter][Mb*counter],min);
			counter++;
		}
		if(min==114514810){
        	System.out.println(-1);
        }
        else{
        	System.out.println(min);
        }
	}
}*/