import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		int max = Integer.parseInt(a) - Integer.parseInt(b);
		for (int i = 0; i < 3; i++) {
			char[] arr = a.toCharArray();
			arr[i] = '9';
			int v = Integer.parseInt(new String(arr)) - Integer.parseInt(b);
			if (max < v) {
				max = v;
			}
		}
		for (int i = 0; i < 3; i++) {
			char[] arr = b.toCharArray();
			if (i == 0) {
				arr[i] = '1';
			} else {
				arr[i] = '0';
			}
			int v = Integer.parseInt(a) - Integer.parseInt(new String(arr));
			if (max < v) {
				max = v;
			}
		}
		System.out.println(max);
	}
}