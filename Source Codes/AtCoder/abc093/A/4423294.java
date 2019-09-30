import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		if(str.contains("a") && str.contains("b") && str.contains("c")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}