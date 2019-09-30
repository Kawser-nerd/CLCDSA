import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int n, s, t,w,a,b;
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		s = sc.nextInt();
		t = sc.nextInt();
		w = sc.nextInt();
		a=0;
		if(s<=w&&w<=t){
			a++;
		}
		for (int i = 1; i <= n-1; i++) {
			b = sc.nextInt();
			w=w+b;
			if(s<=w&&w<=t){
				a++;
			}
		}

		System.out.println(a);

	}
}