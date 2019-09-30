import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String W = sc.next();
		System.out.println(r(r(r(r(r(W, "a"), "i"), "u"), "e"), "o"));
	}

	public static String r(String W, String s) {
		return W.replace(s, "");
	}

}