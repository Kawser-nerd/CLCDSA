import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main{
	static Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		System.out.println(
				REPS(getInt()).mapToObj(i->s.next()).map(o->
					o.toLowerCase()
					.replaceAll("[^b-df-hj-np-tv-xz]","")
					.replaceAll("[bc]","1")
					.replaceAll("[dw]","2")
					.replaceAll("[tj]","3")
					.replaceAll("[fq]","4")
					.replaceAll("[lv]","5")
					.replaceAll("[sx]","6")
					.replaceAll("[pm]","7")
					.replaceAll("[hk]","8")
					.replaceAll("[ng]","9")
					.replaceAll("[zr]","0")
				)
				.filter(o->o.length()>0)
				.collect(Collectors.joining(" "))
				);
	}
}