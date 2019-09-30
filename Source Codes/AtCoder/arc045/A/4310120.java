import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] arr = sc.nextLine().split(" ");
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < arr.length; i++) {
			if (i != 0) {
				sb.append(" ");
			}
			if (arr[i].equals("Left")) {
				sb.append("<");
			} else if (arr[i].equals("Right")) {
				sb.append(">");
			} else {
				sb.append("A");
			}
		}
		System.out.println(sb);
	}
}