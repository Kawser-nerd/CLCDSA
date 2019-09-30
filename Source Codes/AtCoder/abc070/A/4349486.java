import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		if(N.substring(0, 1).equals(N.substring(2, 3))) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}