import static java.lang.System.*;
import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		String s = sc.next();
		int price = 700;
		for (int i=0; i<3; i++) {
			if (s.charAt(i)=='o') price += 100;
		}
		out.println(price);
	}
}