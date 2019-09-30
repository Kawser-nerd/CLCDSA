import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.function.Supplier;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Main{

	private void solve(){
		int h=gInt(),w=gInt();
		HashMap<Long,Integer>m=new HashMap<>();
		for(int q:rep(gInt())) {
			int a=gInt(),b=gInt();
			for(int A:rep(Math.max(1,a-2),Math.min(h-2,a)))
				for(int B:rep(Math.max(1,b-2),Math.min(w-2,b)))
					m.merge(A*1000000000L+B,1,Integer::sum);
		}
		long[]c=new long[10];
		m.values().stream().forEach(i->++c[i]);
		c[0]=(h-2L)*(w-2)-Arrays.stream(c).sum();
		Arrays.stream(c).forEach(System.out::println);
	}
	public static void main(String[]$){
		new Main().solve();
	}

	Scanner s=new Scanner(System.in);

	int gInt(){
		return Integer.parseInt(s.next());
	}
	long gLong(){
		return Long.parseLong(s.next());
	}
	double gDouble(){
		return Double.parseDouble(s.next());
	}

	SupplierIterator<Integer> ints(int n){
		return new SupplierIterator<>(n,this::gInt);
	}
	SupplierIterator<Long> longs(int n){
		return new SupplierIterator<>(n,this::gLong);
	}
	SupplierIterator<Double> doubles(int n){
		return new SupplierIterator<>(n,this::gDouble);
	}
	SupplierIterator<String> strs(int n){
		return new SupplierIterator<>(n,s::next);
	}

	static class SupplierIterator<T> implements Iterable<T>,Iterator<T>{
		int			t;
		Supplier<T>	supplier;

		SupplierIterator(int t,Supplier<T> supplier){
			this.t=t;
			this.supplier=supplier;
		}

		@Override
		public Iterator<T> iterator(){
			return this;
		}

		@Override
		public boolean hasNext(){
			return t>0;
		}

		@Override
		public T next(){
			--t;
			return supplier.get();
		}
	}


	Range rep(int i){
		return Range.rep(i);
	}
	Range rep(int f,int t,int d){
		return Range.rep(f,t,d);
	}
	Range rep(int f,int t){
		return rep(f,t,1);
	}
	Range rrep(int f,int t){
		return rep(f,t,-1);
	}

	static class Range implements Iterable<Integer>,PrimitiveIterator.OfInt{

		int to,cur,d;

		Range(int from,int to,int d){
			this.cur=from-d;
			this.to=to;
			this.d=d;
		}

		Range(int n){
			this(0,n-1,1);
		}

		@Override
		public Iterator<Integer> iterator(){
			return this;
		}

		@Override
		public boolean hasNext(){
			return cur+d==to||(cur!=to&&(cur<to==cur+d<to));
		}

		@Override
		public int nextInt(){
			return cur+=d;
		}

		static Range rep(int i){
			return new Range(i);
		}
		static Range rep(int f,int t,int d){
			return new Range(f,t,d);
		}
		static Range rep(int f,int t){
			return rep(f,t,1);
		}
		static Range rrep(int f,int t){
			return rep(f,t,-1);
		}
	}


	IntStream REP(int v){
		return IntStream.range(0,v);
	}
	IntStream REP(int l,int r){
		return IntStream.rangeClosed(l,r);
	}

	IntStream INTS(int n){
		return REP(n).map(i->gInt());
	}
	Stream<String> STRS(int n){
		return REP(n).mapToObj(i->s.next());
	}
}