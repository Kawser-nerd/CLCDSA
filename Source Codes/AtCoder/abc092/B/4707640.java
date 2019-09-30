import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int x = sc.nextInt();
		int [] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j <= d; j++ ) {
				if(j*a[i]+1 <= d) {
					x++;
				}
				else {
					break;
				}
			}
		}
		System.out.println(x);
		sc.close();
	}

}