import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int[]a=new int[n];
		int max=0;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			if(max<a[i]) {
				max=a[i];
			}
		}
		if(max<k) {
			System.out.println("IMPOSSIBLE");
			return;
		}
		Arrays.sort(a);
		for(int i=0;i<n-1;i++) {
			a[i+1]=koyaku(a[i],a[i+1]);
		}
		if(k%a[n-1]==0) {
			System.out.println("POSSIBLE");
		}else {
			System.out.println("IMPOSSIBLE");
		}
	}
	static int koyaku(int b,int a) {
		int mod;
		while(true){
			mod=a%b;
			if(mod==0) {
				return b;
			}
			a=b;
			b=mod;
		}
	}
}