import java.util.Scanner;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {

		sc = new Scanner(System.in);
		String str = sc.next();
		int len = str.length();
		int midLen = len -2;

		System.out.print(str.substring(0,1) + midLen + str.substring(len-1,len));
	}

}