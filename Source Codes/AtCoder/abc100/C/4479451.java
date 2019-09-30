import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		for(int i=0;i<n;i++) {
			int m=sc.nextInt();
			for(;;) {
				if(m%2==0) {
					m/=2;ans++;
				}else {
					break;
				}
			}
		}
	System.out.println(ans);
	}
}