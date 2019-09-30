import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<=n;i+=7) {
			for(int j=0;i+j<=n;j+=4) {
				if(i+j==n) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}