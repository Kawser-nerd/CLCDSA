import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		String str = sc.next();
		
		int start = str.indexOf("A");
		int end = str.lastIndexOf("Z");
		
		System.out.println(end - start + 1);
	}
}