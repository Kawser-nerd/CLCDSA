import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.next().split("");
		boolean I = false;
		boolean C = false;
		boolean T = false;
		for (int i = 0; i < s.length; i++) {
			if (s[i].equals("I") || s[i].equals("i"))
				I = true;
			if ((s[i].equals("C") || s[i].equals("c")) && I)
				C = true;
			if ((s[i].equals("T") || s[i].equals("t")) && C)
				T = true;
		}
		if (T)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}