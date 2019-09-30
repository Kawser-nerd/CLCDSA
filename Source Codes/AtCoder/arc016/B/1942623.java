import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Main{
	private void solve(){
		int n=gInt();
		char[][]f=new char[n+1][];
		f[0]=new char[9];
		for(int i:rep(1,n))
			f[i]=s.next().toCharArray();

		int r=0;
		for(int i:rep(1,n)) {
			for(int j:rep(9)) {
				if(f[i][j]=='x')
					++r;
				else if(f[i][j]=='o'&&f[i-1][j]!='o')
					++r;
			}
		}
		System.out.println(r);
	}

	public static void main(String[]$){
		new Main().solve();
		System.out.flush();
	}

	static class System{
		private static final InputStream in=java.lang.System.in;
		private static final PrintWriter out=new PrintWriter(java.lang.System.out,false);
	}
	static Scanner s=new Scanner(System.in);

	static int gInt(){
		return s.nextInt();
	}
	static long gLong(){
		return s.nextLong();
	}
	static long gDouble(){
		return s.nextLong();
	}

	static Range rep(int i){
		return new Range(i);
	}
	static Range rep(int f,int t){
		return new Range(f,t);
	}
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

	static IntStream REPS(int v){
		return IntStream.range(0,v);
	}
	static IntStream REPS(int l,int r){
		return IntStream.rangeClosed(l,r);
	}

	static IntStream ints(int n){
		return REPS(n).map(i->gInt());
	}
	static Stream<String> strs(int n){
		return REPS(n).mapToObj(i->s.next());
	}
}