import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
 
		String o = sc.next();
		String e = sc.next();
 
		for (int i = 0; i < o.length(); i++) {
			System.out.print("" + o.charAt(i) + (i < e.length() ? e.charAt(i) : ""));
		}
		System.out.println();
	}
 
}