import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] arr1 = sc.next().split("\\+");
		int count = 0;
		for (String s1 : arr1) {
			String[] arr2 = s1.split("\\*");
			boolean zero = false;
			for (String s2 : arr2) {
				if (s2.equals("0")){
					zero = true;
				}
			}
			if (!zero) {
				count++;
			}
		}
		System.out.println(count);
	}
}