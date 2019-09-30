import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int h=sc.nextInt();
		int ans=0;
		Integer[]b=new Integer[n];
		int maxA=0;
		for(int i=0;i<n;i++) {
			maxA=Math.max(maxA, sc.nextInt());
			b[i]=sc.nextInt();
		}
		Arrays.sort(b,Collections.reverseOrder());
		for(int i=0;i<n;i++) {
			if(b[i]>maxA) {
				h-=b[i];
				ans++;
			}else {
				break;
			}
			if(h<=0) {
				System.out.println(ans);
				return;
			}
		}
		ans+=h/maxA;
		if(h%maxA!=0) {
			ans++;
		}
		System.out.println(ans);
	}
}