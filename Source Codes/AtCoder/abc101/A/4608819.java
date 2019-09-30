import java.util.Scanner;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		Scanner sc = new Scanner(System.in);

		// ----- main -----
		int ans = 0;
		String s = sc.nextLine();
		for(int i=0; i < s.length(); i++) {
			if('+' == s.charAt(i)) {
				ans++;
			} else {
				ans--;
			}
		}
		System.out.println(ans);
	}
}