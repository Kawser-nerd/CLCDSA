import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		System.out.println((s.lastIndexOf("Z") - s.indexOf("A")) + 1);
	}

}