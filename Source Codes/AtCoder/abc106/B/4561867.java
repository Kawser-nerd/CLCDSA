import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		for(int i=99;i<=n;i+=2) {
			int yakusu=0;
			for(int j=1;j<=n;j++) {
				if(i%j==0) {
					yakusu++;
				}
			}
			if(yakusu==8) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}