import java.util.BitSet;
import java.util.NoSuchElementException;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static Scanner s=new Scanner(System.in);
	static int getInt(){return Integer.parseInt(s.next());}

	static int[][]f;
	static final int[]dx={-1,0,1,0},dy={0,-1,0,1};
	public static void main(String[]$){
		int n=getInt();
		long r=1;

		PrimeIterator pr=new PrimeIterator(n);

		for(int p:pr) {
			int c=1;
			for(int j=p;j<=n;j*=p) {
				c+=n/j;
			}
			r*=c;
			r%=1000000007;
		}
		System.out.println(r);
	}
	public static class PrimeIterator implements Iterable<Integer>,PrimitiveIterator.OfInt{
		private BitSet	bs;
		private int		curv,limit;

		//todo
		//public PrimeIterator(int from,int limit);
		public PrimeIterator(int limit){
			curv=0;
			bs=new BitSet(limit+1);
			this.limit=limit;
			constructBS();
		}
		private final void constructBS(){
			bs.set(0,limit+1);
			bs.clear(0);
			bs.clear(1);
			if(limit<2) return;

			int i=2;
			while(sieve(i=bs.nextSetBit(i)))
				i++;
		}
		protected boolean sieve(int v){
			final long sievestart=1L*v*v;
			if(4>sievestart||sievestart>limit)
				return false;
			IntStream.iterate(v*v,i->i+v).limit(limit/v-v+1).forEach(bs::clear);
			return true;
		}
		@Override
		public boolean hasNext(){
			final int r=getNextValue();
			return 0<=r&&r<=limit;
		}
		private int getNextValue(){
			return bs.nextSetBit(curv+1);
		}
		@Override
		public int nextInt(){
			final int r=getNextValue();
			if(r<0||limit<r) throw new NoSuchElementException();
			return curv=r;
		}
		@Override
		public OfInt iterator(){
			return this;
		}
		public BitSet getClonedBitSet(){
			return bs.get(0,limit+1);
		}
	}
}