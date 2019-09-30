import java.util.*;

public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int R = stdin.nextInt();
			int C = stdin.nextInt();
			int W = stdin.nextInt();

			int res=0;

			if (C%W == 0) {
				res = R*(C/W) + W - 1;
			}
			else {
				res = R*(C/W) + W;
			}

			System.out.println("Case #"+loop+": "+res);

		}
	}
}