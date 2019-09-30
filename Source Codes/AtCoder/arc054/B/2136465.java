import java.util.Iterator;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.function.DoubleUnaryOperator;
import java.util.function.Supplier;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Main{
	static Scanner s=new Scanner(System.in);

	private void solve(){
		double p=gDouble();
		DoubleUnaryOperator f=i->i+p/Math.pow(2,i/1.5);
		double x=goldenSelectionSearch(0,p,1e-9,f);
		System.out.println(f.applyAsDouble(x));
	}
	private double goldenSelectionSearch(double l,double r,final double off,DoubleUnaryOperator f){
		final double g=(1+Math.sqrt(5))/2;
		double a=(l*g+r)/(1+g),fa=f.applyAsDouble(a);
		double b=(l+r*g)/(1+g),fb=f.applyAsDouble(b);
		while(l+off<r){
			if(fa<=fb) {
				r=b;
				b=a;
				fb=fa;
				a=(l*g+r)/(1+g);
				fa=f.applyAsDouble(a);
			}else {
				l=a;
				a=b;
				fa=fb;
				b=(l+r*g)/(1+g);
				fb=f.applyAsDouble(b);
			}
		}
		return (a+b)/2;
	}

	public static void main(String[]$){
		new Main().solve();
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
		return rep(t,f,-1);
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