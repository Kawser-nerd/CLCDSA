import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int M = (n*(n-1))/2 - n/2;
		System.out.println(M);
		if(n%2==0) {
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++) {
					if (i+j==n+1) continue;
					System.out.println(i + " " + j);
				}
			}
		}
		else {
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n-1;j++) {
					if (i+j==n) continue;
					System.out.println(i + " " + j);
				}
				System.out.println(i + " " + n);
			}
		}
	}
}