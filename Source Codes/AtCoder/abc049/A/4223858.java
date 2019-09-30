import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char a = sc.next().charAt(0);
		System.out.println(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o' ? "vowel" : "consonant");
	}
}