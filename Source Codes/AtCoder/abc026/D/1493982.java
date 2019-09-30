import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static Scanner s=new Scanner(System.in);
	static int getInt(){return Integer.parseInt(s.next());}
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static class Pair<T,U>{
		T l;U r;
		Pair(T L,U R){l=L;r=R;}
		T getL(){return l;}
		U getR(){return r;}
	}

	static final int a=getInt(),b=getInt(),c=getInt();
	public static void main(String[]$){
		double d=1,t=0;
		while(true){
			if(f(d+t)<100)
				t+=d;
			else
				d/=10;
			if(Math.abs(f(t)-100)<=0.000001)
				break;
		}
		System.out.println(t);
		//System.out.println(f(t));
	}
	static double f(double t) {
		return t*a+Math.sin(t*c*Math.PI)*b;
	}
}