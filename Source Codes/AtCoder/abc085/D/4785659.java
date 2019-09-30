import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long h = sc.nextLong();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		int ans = 0;
		long dame = 0;
		Arrays.sort(a);
		Arrays.sort(b);
		for(int i = n-1; i >= 0 && dame < h; i--){
			if(b[i] > a[n-1]){
				ans++;
				dame+=b[i];
			}else{
				break;
			}
		}
		ans+=h-dame>0?(int)((h-dame)/a[n-1])+((h-dame)%a[n-1]==0?0:1):0;
		System.out.print(ans);
	}
}