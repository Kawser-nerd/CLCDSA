import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n=sc.nextInt(), x=sc.nextInt();
		int min = Integer.MAX_VALUE;
		for (int i=0; i<n; i++) {
			int temp = sc.nextInt();
			min = Math.min(min,temp);
			x -= temp;
		}
		out.println(n+(x/min));
	}
}