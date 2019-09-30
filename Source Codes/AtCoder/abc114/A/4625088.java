import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int X = scn.nextInt();
		System.out.println((X==7|X==5|X==3)?"YES":"NO");
	}

}