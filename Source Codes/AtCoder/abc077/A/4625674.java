import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		char[] a = scn.nextLine().toCharArray();
		char[] b = scn.nextLine().toCharArray();
		boolean ans = true;
		for(int i = 0;i < 3;i++) {
			ans &= a[i]==b[2-i];
		}
		System.out.println(ans?"YES":"NO");
	}

}