import java.util.HashSet;
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
		int r=-1,n=s.nextInt();
		String in=s.next();
		HashSet<String>set=new HashSet<>(100);
		set.add(in);
		for(int i=1;i<n;i++) {
			String nin=s.next();
			if(nin.charAt(0)!=in.charAt(in.length()-1)||set.contains(nin)) {
				r=i;
				break;
			}
			in=nin;
			set.add(in);
		}
		System.out.println(r==-1?"DRAW":r%2==1?"WIN":"LOSE");
	}
}