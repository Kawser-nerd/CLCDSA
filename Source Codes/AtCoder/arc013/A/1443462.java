import java.util.Scanner;
import java.util.function.BiFunction;
public class Main{
	static final Scanner s=new Scanner(System.in);
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	@SafeVarargs
	static <T> T ofAll(BiFunction<T,T,T>funk,T...a) {
		T t=a[0];
		for(int i=1;i<a.length;i++)
			t=funk.apply(t,a[i]);
		return t;
	}
	static int
	n=getInt(),
	m=getInt(),
	l=getInt(),
	p=getInt(),
	q=getInt(),
	r=getInt();
	public static void main(String[]$){
		System.out.println(
				ofAll(
						Integer::max,
						solve(p,q,r),
						solve(p,r,q),
						solve(q,p,r),
						solve(q,r,p),
						solve(r,p,q),
						solve(r,q,p)
						)
				);
	}
	static int solve(int x,int y,int z) {
		return (n/x)*(m/y)*(l/z);
	}
}