import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		for(int i=0;i<n;i++) {
			double a=sc.nextDouble();
			int j=0;
			for(;a>=2;j++) {
				a/=2;
				if(a%1!=0) {
					break;
				}
			}
			ans+=j;
		}
		System.out.println(ans);
	}
}