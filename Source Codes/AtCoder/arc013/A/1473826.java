import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n){return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	static int
	n=getInt(),
	m=getInt(),
	l=getInt();
	public static void main(String[]$){
		int
		p=getInt(),
		q=getInt(),
		r=getInt();

		System.out.println(Arrays.stream(new int[] {
				hoge(p,q,r),
				hoge(p,r,q),
				hoge(q,p,r),
				hoge(q,r,p),
				hoge(r,p,q),
				hoge(r,q,p)
		}).max().getAsInt());
	}
	static int hoge(int p,int q,int r) {
		 return (n/p)*(m/q)*(l/r);
	}
}