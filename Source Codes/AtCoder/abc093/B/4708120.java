import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int x = b-a+1;
		for(int i = 0; i < k; i++) {
			if(k > x) {
				for(int j = 0; j <= b-a; j++) {
					System.out.println(a+j);
				}
				break;
			}
			System.out.println(a+i);
		}
		for(int i = k - 1; i >= 0; i-=1) {
			if(a+k-1 < b - i) {
				System.out.println(b-i);
			}
		}
		sc.close();
	}

}