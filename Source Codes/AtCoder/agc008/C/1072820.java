import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long xi = sc.nextLong();
		long xo = sc.nextLong();
		long xt = sc.nextLong();
		long xj = sc.nextLong();
		long xl = sc.nextLong();
		long ans1 = 0;
		long ans2 = 0;

		ans1 += (xj/2)*2;
		ans1 += (xl/2)*2;
		ans1 += (xi/2)*2;
		ans1 += xo;

		if( xi != 0 && xj != 0 && xl != 0 ){
			ans2 += 3;
			xj--; xl--; xi--;
		}
 
		ans2 += (xj/2)*2;
		ans2 += (xl/2)*2;
		ans2 += (xi/2)*2;
		ans2 += xo;
 
		System.out.println(Math.max(ans1,ans2));
		return;
	}
}