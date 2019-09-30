import java.util.Iterator;
import java.util.PrimitiveIterator;
import java.util.Scanner;

class Main{
	public static void main(String[]$){
		int a=0,b=0,c=0,d=0,e=0,f=0;
		for(int v:new Range(gInt())) {
			double high=s.nextDouble(),low=s.nextDouble();
			if(high>=35)++a;
			if(35>high&&high>=30)++b;
			if(30>high&&high>=25)++c;
			if(low>=25)++d;
			if(low<0&&high>=0)++e;
			if(high<0)++f;
		}
		System.out.println(a+" "+b+" "+c+" "+d+" "+e+" "+f);
	}

	static Scanner s=new Scanner(System.in);
	static int gInt() {return Integer.parseInt(s.next());}
	static long gLong() {return Long.parseLong(s.next());}

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