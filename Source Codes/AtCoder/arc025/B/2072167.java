import java.util.Arrays;
import java.util.Iterator;
import java.util.PrimitiveIterator;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Main{

	private void solve(){
		int h=gInt(),w=gInt();
		int[][][]f=new int[2][h+1][w+1];
		
		for(int i:rep(1,h))
			for(int j:rep(1,w))
				f[(i+j)%2][i][j]=gInt();
		for(int i:rep(1,h)) {
			Arrays.parallelPrefix(f[0][i],Integer::sum);
			Arrays.parallelPrefix(f[1][i],Integer::sum);
		}
		
		for(int i:rep(1,h)){
			for(int j:rep(1,w)){
				f[0][i][j]+=f[0][i-1][j];
				f[1][i][j]+=f[1][i-1][j];
			}
		}
		
		/*
		for(int i:rep(h+1))
			System.out.println(Arrays.toString(f[0][i]));
		for(int i:rep(h+1))
			System.out.println(Arrays.toString(f[1][i]));
		/**/
		
		int r=0;
		for(int fi:rep(1,h)) {
			for(int fj:rep(1,w)) {
				for(int ti:rep(fi,h)) {
					for(int tj:rep(fj,w)) {
						int[][] a=f[0];
						int va=a[ti][tj]-a[fi-1][tj]-a[ti][fj-1]+a[fi-1][fj-1];
						int[][] b=f[1];
						int vb=b[ti][tj]-b[fi-1][tj]-b[ti][fj-1]+b[fi-1][fj-1];
						if(va==vb)
							r=Math.max(r,(ti-fi+1)*(tj-fj+1));
					}
				}
			}
		}
		System.out.println(r);
	}

	public static void main(String[]$){
		new Main().solve();
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
	static Range rep(int f,int t,int d){
		return new Range(f,t,d);
	}
	static Range rep(int f,int t){
		return rep(f,t,1);
	}
	static Range rrep(int f,int t){
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