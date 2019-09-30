import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n = sc.nextInt();
		int l = sc.nextInt();
		int[] a = new int[n];
		for (int i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		int b = last(a,l);
		if (b==-1) {
			System.out.println("Impossible");
		} else {
			System.out.println("Possible");
			for (int i=0;i<b;i++) {
				System.out.println(i+1);
			}
			for (int i=n-2;i>b;i--) {
				System.out.println(i+1);
			}
			System.out.println(b+1);
		}
	}

	static int last(int[] a, int l) {
		for (int i=0;i<a.length-1;i++) {
			if(a[i]+a[i+1] >= l) {
				return i;
			}
		}

		return -1;
	}

}