import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i=0;i<n;i++) {
			a[i]=sc.nextLong();
		}

		System.out.println(check(a)? "YES" : "NO");

	}

	static boolean check (long[] a) {
		int n = a.length;

		long sum = 0;
		for (int i=0;i<n;i++) {
			sum+=a[i];
		}

		if (sum%((long)n*(n+1)/2) != 0) {
			return false;
		} else {
			long step = sum/((long)n*(n+1)/2);
			long count = 0;
			for (int i=0;i<n-1;i++) {
				if ((a[i]-a[i+1]+step)%n != 0 || a[i]-a[i+1]+step < 0) {
					return false;
				}
				count += (a[i]-a[i+1]+step)/n;
			}

			if((a[n-1]-a[0]+step)%n != 0 || a[n-1]-a[0]+step < 0) {
				return false;
			} else {
				count += (a[n-1]-a[0]+step)/n;
			}

			return count==step;
		}
	}

}