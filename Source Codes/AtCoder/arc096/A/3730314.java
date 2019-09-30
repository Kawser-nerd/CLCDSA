import java.util.*;
public class Main {
	
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		
		if (a + b > 2 * c) {
			int ans = 0;
			
			int min = Math.min(x, y);
			ans = min*2*c;
			x-=min;
			y-=min;
			
			if (x > 0 && a > 2*c) {
				ans += x*2*c;
				x = 0;
			}
			
			if (y > 0 && b > 2*c) {
				ans += y*2*c;
				y = 0;
			}
			
			ans += a*x + b*y;
			
			System.out.println(ans);
		} else {
			System.out.println(a*x + b*y);
		}
	}
}