import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		S = S.substring(0, 1).toUpperCase() + S.substring(1).toLowerCase();
		System.out.println(S);
	}

}