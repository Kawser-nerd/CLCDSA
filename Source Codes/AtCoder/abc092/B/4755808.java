import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int day = sc.nextInt();
		int x = sc.nextInt();
		
		int total = 0;
		for (int i=0; i<n; i++) {
			int a = sc.nextInt();
			if (day%a==0) {
				total += day/a;
			}
			else {
				total += day/a + 1;
			}
		}
		
		out.println(total+x);
	}
}