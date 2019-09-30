import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String eat = sc.next();
		System.out.println((eat.length() - eat.replace("+", "").length()) * 2 - 4);
	}
}