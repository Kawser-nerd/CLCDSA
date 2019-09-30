import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
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
				chikan[counter].add(i);
				before=i;
				now=amida[i];
				while(amari[now]==-1) {
					amari[now]=amari[before]+1;
					attri[now]=counter;
					chikan[counter].add(now);
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
			goal[chikan[zokusei].get((amr+D)%vol)]=i;
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
	public static class Vertex{
		ArrayList <Integer> rinsetu=new ArrayList<Integer>();
		public void add(int V) {
			rinsetu.add(V);
		}
		public int get(int i) {
			return rinsetu.get(i);   //Pair??????
		}
		public int size() {
			return rinsetu.size();   //Pair??????
		}
	}
}