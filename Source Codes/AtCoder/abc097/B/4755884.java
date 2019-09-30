import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int x = sc.nextInt();
		TreeSet<Integer> set = new TreeSet<>();
		set.add(1);
		for (int i=2; i<=33; i++) {
			for (int j=2; j<=100; j++) {
				if (Math.pow(i,j) > x) break;
				set.add((int)Math.pow(i,j));
			}
		}
		
		int ans = 1;
		for (Integer n: set) {
			if (n > x) break;
			ans = n;
		}
		out.println(ans);
	}
}