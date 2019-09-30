import java.util.Scanner;

public class Main {

	void	 solve() {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		char c1 = s.charAt(0), c2 = Character.toUpperCase(s.charAt(2));
		System.out.println(c1 == c2 ? "Yes" : "No");
	}
	public static void main(String[] args) throws Exception{
		new Main().solve();
	}
}