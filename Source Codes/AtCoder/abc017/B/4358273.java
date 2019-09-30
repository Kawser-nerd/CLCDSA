import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		String ans = s.replaceAll("ch", "").replaceAll("o", "").replaceAll("k", "").replaceAll("u", "").isEmpty() ? "YES" : "NO";
		System.out.println(ans);
	}
	
}