import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String b = sc.next();
		
		char x = b.charAt(0);
		
		if(x == 'A') {
			System.out.println("T");
		} else if(x == 'T') {
			System.out.println("A");
		} else if(x == 'G') {
			System.out.println("C");
		} else if(x == 'C') {
			System.out.println("G");
		}
		
	}
}