import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n){return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}
	public static void main(String[]$){
		int n=getInt(),a=getInt(),b=getInt();
		double d[]=INS(n).asDoubleStream().toArray();

		double
		min=Arrays.stream(d).min().getAsDouble(),
		max=Arrays.stream(d).max().getAsDouble(),
		r=b/(max-min);
		REPS(n).forEach(i->d[i]*=r);

		if(Double.isInfinite(r)) {
			System.out.println(-1);
		}else {
			System.out.printf(
					"%f %f\n",
					r,
					a-Arrays.stream(d).average().getAsDouble()
					);
		}
	}
}