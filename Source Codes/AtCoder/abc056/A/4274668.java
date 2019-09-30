import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String a = sc.next();
		String b = sc.next();
		
		String res = a+b;
		
		if(res.equals("HH")) {
			System.out.println("H");
		}else if(res.equals("DD")) {
			System.out.println("H");
		}else {
			System.out.println("D");
		}
	}
}