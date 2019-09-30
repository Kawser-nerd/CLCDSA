import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		System.out.println((a.length() - a.replace("o","").length()) * 100 + 700);
	}
}