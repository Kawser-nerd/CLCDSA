import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		int n = sc.nextInt();
		String[] ss = new String[5];
		for (int i = 0; i < s.length(); i++) {
			ss[i] = s.charAt(i) + "";
		}
		List<String> list = new ArrayList<>();
		for (int i = 0; i < ss.length; i++) {
			for (int j = 0; j < ss.length; j++) {
				list.add(ss[i] + ss[j]);
			}
		}
		System.out.println(list.get(n - 1));
	}
}