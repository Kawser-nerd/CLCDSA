import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		double ans=0;
		for(int i = 0; i<n; i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			a[i]=x;
			b[i]=y;
		}
		for(int i = 0; i<n; i++){
			for(int j = i; j<n; j++){
				if(Math.sqrt(Math.pow(Math.abs(a[i]-a[j]),2)+Math.pow(Math.abs(b[i]-b[j]),2))>ans){
					ans=Math.sqrt(Math.pow(Math.abs(a[i]-a[j]),2)+Math.pow(Math.abs(b[i]-b[j]),2));
				}
			}
		}
		System.out.println(ans);
	}
}