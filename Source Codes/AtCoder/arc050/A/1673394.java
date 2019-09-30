import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String C = sc.next();
		String c = sc.next();
		if(C.toLowerCase().equals(c)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}