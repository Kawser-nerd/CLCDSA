import java.io.*;
import java.math.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int cas = 1; cas <= tests; cas++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			String a[] = new String[n + m];
			for (int i = 0; i < n + m; i++) {
				a[i] = sc.next();
			}
			HashSet<Long> set = new HashSet<Long>();
			set.add(0L);
			for (int i = 0; i < n; i++) {
				String s = a[i];
				long hashValue = 0;
				for (int j = 0; j < s.length(); j++) {
					if (s.charAt(j) == '/') {
						set.add(hashValue);
					}
					hashValue = hashValue * 3137 + s.charAt(j);
				}
				set.add(hashValue);
			}
			int count1 = set.size();
			for (int i = n; i < n + m; i++) {
				String s = a[i];
				long hashValue = 0;
				for (int j = 0; j < s.length(); j++) {
					if (s.charAt(j) == '/') {
						set.add(hashValue);
					}
					hashValue = hashValue * 3137 + s.charAt(j);
				}
				set.add(hashValue);
			}
			int count2 = set.size();
			System.out.println("Case #" + cas + ": " + (count2 - count1) );
		}
	}
}
