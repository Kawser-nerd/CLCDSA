import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] arr = s.toLowerCase().toCharArray();
		arr[0] = (char)(arr[0] - 'a' + 'A');
		System.out.println(arr);
	}
}