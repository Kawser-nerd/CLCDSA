import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.PrimitiveIterator;
import java.util.Scanner;

class Main{
	public static void main(String[]$){
		int n=gInt();
		HashMap<String,String>m=new HashMap<>();
		for(int i:rep(n)) {
			String in=s.next();
			String sb=new StringBuilder(in).reverse().toString();
			m.put(in,sb);
		}
		m.entrySet().stream()
		.sorted(Entry.comparingByValue())
		.map(Entry::getKey)
		.forEach(System.out::println);
	}

	static Scanner s=new Scanner(System.in);
	static int gInt() {return Integer.parseInt(s.next());}
	static long gLong() {return Long.parseLong(s.next());}

	static Range rep(int i) {return new Range(i);}
	static Range rep(int f,int t) {return new Range(f,t);}
	static class Range implements Iterable<Integer>,PrimitiveIterator.OfInt{
		int from,to,c;
		Range(int from,int to){
			this.from=from;
			this.to=to;
			this.c=from;
		}
		Range(int n){
			this(0,n-1);
		}
		@Override
		public Iterator<Integer> iterator(){
			return this;
		}
		@Override
		public boolean hasNext(){
			return c<=to;
		}
		@Override
		public int nextInt(){
			return c++;
		}
	}
}