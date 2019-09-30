import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int cnt,max=0,ans=0;
		for(int i=1;i<=n;i++) {
			cnt=0;
			int j=i;
			for(cnt=0;true;cnt++) {
				if(j%2==0) {
					j/=2;
				}else {
					break;
				}
			}
			if(max<cnt) {
				max=cnt;
				ans=i;
			}
		}
		System.out.println(n==1?1:ans);
	}
}