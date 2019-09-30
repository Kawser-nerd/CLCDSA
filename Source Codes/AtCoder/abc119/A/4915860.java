import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		int intInput = Integer.parseInt(input.replaceAll("/", ""));
		if(intInput > 20190430) {
			System.out.println("TBD");
		}else {
			System.out.println("Heisei");
		}
		sc.close();
	}
}