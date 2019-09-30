import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.function.Supplier;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Main{

	static class Edge{
		int a,b,c;

		public Edge(int a,int b,int c){
			this.a=a;
			this.b=b;
			this.c=c;
		}
	}

	static Scanner s=new Scanner(System.in);

	private void solve(){
		TreeMap<Integer,List<Edge>>a=new TreeMap<>();
		int n=gInt(),m=gInt();
		long[]pos=new long[n];
		final long DEFAULT=Long.MAX_VALUE;
		Arrays.fill(pos,DEFAULT);

		for(int q:rep(m)) {
			int l=gInt()-1,r=gInt()-1,d=gInt();

			a.computeIfAbsent(l,(i)->new ArrayList<>()).add(new Edge(l,r,d));
			a.computeIfAbsent(r,(i)->new ArrayList<>()).add(new Edge(r,l,-d));
		}

		ArrayDeque<Edge>d=new ArrayDeque<>();
		while(!a.isEmpty()) {
			d.addAll(a.pollFirstEntry().getValue());
			while(!d.isEmpty()) {
				Edge o=d.poll();
				if(pos[o.a]==DEFAULT) {
					pos[o.a]=0;
				}
				if(pos[o.b]==DEFAULT) {
					pos[o.b]=pos[o.a]+o.c;
					List<Edge> v=a.remove(o.b);
					if(v!=null)
						d.addAll(v);
				}else if(pos[o.b]-pos[o.a]!=o.c) {
					System.out.println("No");
					return;
				}
			}
		}
		System.err.println(a);
		System.out.println("Yes");
	}

	public static void main(String[]$){
		new Main().solve();
	}


	int abs(int v){
		return (v^(v>>31))-(v>>31);
	}
	long abs(long v){
		return (v^(v>>63))-(v>>63);
	}

	int gInt(){
		return Integer.parseInt(s.next());
	}
	long gLong(){
		return Long.parseLong(s.next());
	}
	double gDouble(){
		return Double.parseDouble(s.next());
	}

	SupplyingIterator<Integer> ints(int n){
		return new SupplyingIterator<>(n,this::gInt);
	}
	SupplyingIterator<Long> longs(int n){
		return new SupplyingIterator<>(n,this::gLong);
	}
	SupplyingIterator<Double> doubles(int n){
		return new SupplyingIterator<>(n,this::gDouble);
	}
	SupplyingIterator<String> strs(int n){
		return new SupplyingIterator<>(n,s::next);
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

	IntStream REP(int v){
		return IntStream.range(0,v);
	}
	IntStream REP(int l,int r){
		return IntStream.rangeClosed(l,r);
	}

	IntStream INTS(int n){
		return IntStream.generate(this::gInt).limit(n);
	}
	Stream<String> STRS(int n){
		return Stream.generate(s::next).limit(n);
	}
}

class SupplyingIterator<T> implements Iterable<T>,Iterator<T>{
	int			t;
	Supplier<T>	supplier;

	SupplyingIterator(int t,Supplier<T> supplier){
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

class Range implements Iterable<Integer>,PrimitiveIterator.OfInt{
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