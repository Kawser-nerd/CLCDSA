import java.util.Scanner;
import java.util.function.LongSupplier;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static final long[] fal_rnd(long[] ar,LongSupplier sp){
		int l=-1,r=ar.length;
		while(l+1!=r)
			ar[Math.random()<0.5?++l:--r]=sp.getAsLong();
		return ar;
	}
	static final IntStream REPS(int v){
		return IntStream.range(0,v);
	};
	public static void main(String[] __){
		int n=s.nextInt(),chokudai=s.nextInt(),kame=s.nextInt();
		double dist=s.nextInt();
		
		for(int i=0;i<n;i++) {
			dist=dist/chokudai*kame;
		}
		System.out.printf("%.20f",dist);
	}
}