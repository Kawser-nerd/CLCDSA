import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int cnt = 0;

		for (int i = A; i <= B; i++) {
			String s = String.valueOf(i);
			char[] c = s.toCharArray();
			boolean x = f(c);
			if(x) cnt++;
		}
		
		System.out.println(cnt);

		sc.close();

	}

	static boolean f(char[] a) {
		boolean x = false;
		int l = a.length - 1;
		int cnt = 0;
		for (int i = 0; i < a.length / 2; i++) {
			if (a[i] == a[l - i])
				cnt++;
		}
		if (cnt == a.length / 2)
			x = true;
		return x;
	}

}