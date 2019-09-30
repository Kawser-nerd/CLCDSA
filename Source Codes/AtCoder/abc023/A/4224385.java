import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		System.out.println(Character.getNumericValue(a.charAt(0)) + Character.getNumericValue(a.charAt(1)));
	}
}