import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int K = scan.nextInt();
		String S = scan.next();
		scan.close();
		if(K == 1 || K == 0) {
			System.out.println(S);
			System.exit(0);
		}
		ArrayList<String> list = new ArrayList<String>();
		char []c = new char[N];
		char []c0 = new char[N];
		char []c1 = new char[N];
		for(int i = 0; i < N; i++) {
			c[i] = S.charAt(i);
			c0[i] = S.charAt(i);
			c1[i] = S.charAt(i);
			list.add(S.substring(i, i + 1));
		}
		Arrays.sort(c);
		Collections.sort(list);
		char []b = new char[N];
		copy(b, c0);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < list.size(); j++) {
				String t = list.get(j);
				char k = t.charAt(0);
				sort1(c1, k, i);
				sort(c1, c0, i);
//				System.out.print(i + " ");
//				disp(c1);
				int cnt = count(c1, c0);

				if(cnt <= K) {
					copy(b, c1);
					list.remove(j);
					break;
				}
			}
		}
		disp(b);


	}
	public static void disp(char []c) {
		for(int i = 0; i < c.length - 1; i++) {
			System.out.print(c[i]);
		}
		System.out.println(c[c.length - 1]);
	}
	public static void copy(char[] b, char  []c1) {
		for(int i = 0; i < b.length; i++) {
			b[i] = c1[i];
		}
	}
	public static void sort1(char[]c1, char t, int a) {
		for(int i = a; i < c1.length; i++) {
			if(c1[i] == t) {
				swap(c1, a, i);
			}
		}
	}
	public static int count(char[] c1, char[] c0) {
		int cnt = 0;
		for(int i = 0; i < c1.length; i++) {
			if(c1[i] != c0[i]) {
				cnt ++;
			}
		}
		return cnt;
	}
	public static void sort(char[] c1, char[] c0, int a) {
		int b = a + 1;
		for(int i = b; i < c1.length; i++) {
			char t = c0[i];
			for(int j = b; j < c1.length; j++) {
				if(t == c1[j]) {
					if(c0[j] != c1[j]) {
						swap(c1, i, j);
						break;
					}
				}
			}
		}
	}
	public static void swap(char[] c1, int i, int j) {
		char t = c1[i];
		c1[i] = c1[j];
		c1[j] = t;
	}
}