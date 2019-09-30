import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		char[] a = scn.nextLine().toCharArray();
		char[] b = scn.nextLine().toCharArray();
		char[] c = scn.nextLine().toCharArray();
		String ans = "";
		ans += a[0];
		ans += b[1];
		ans += c[2];
		System.out.println(ans);
	}

}