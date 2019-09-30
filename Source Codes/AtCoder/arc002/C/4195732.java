import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		char[] arr = new char[]{'A', 'B', 'X', 'Y'};
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				for (int k = 0; k < arr.length; k++) {
					for (int l = 0; l < arr.length; l++) {
						if (i == k && j == l) {
							continue;
						}
						String x = s.replaceAll(String.valueOf(arr[i]) + String.valueOf(arr[j]), "L");
						x = x.replaceAll(String.valueOf(arr[k]) + String.valueOf(arr[l]), "R");
						int len = x.length();
						if (min > len) {
							min = len;
						}
					}
				}
			}
		}
		System.out.println(min);
	}
}