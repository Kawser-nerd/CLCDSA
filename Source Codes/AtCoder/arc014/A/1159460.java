import java.util.Scanner;

class Main {
	public static void main (String[ ] args) {
		Scanner scanner = new Scanner (System.in);
		
		//??
		int ret = scanner.nextInt( ) ;
		
		//??
		if (ret % 2 == 0) {
			System.out.println("Blue");
		}else {
			System.out.println("Red");
		}
	}
}