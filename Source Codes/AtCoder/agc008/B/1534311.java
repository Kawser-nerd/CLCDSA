import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		long[]a=new long[n];
		long[] sum_a=new long[n];
		long[] sum_b=new long[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextLong();
			if(i==0){
				sum_a[i]=a[i];
				sum_b[i]=Math.max(0, a[i]);
			}else{
				sum_a[i]=sum_a[i-1]+a[i];
				sum_b[i]=sum_b[i-1]+Math.max(0, a[i]);
			}
		}
		long ans=0;
		for(int i=0;i<=n-k;i++){
			long sum_black=0;
			long sum_white=0;
			if(i==0)sum_black+=sum_a[i+k-1];
			else sum_black+=sum_a[i+k-1]-sum_a[i-1];
			
			if(i>0){
				sum_black+=sum_b[i-1];
				sum_white+=sum_b[i-1];
			}
			sum_black+=sum_b[n-1]-sum_b[i+k-1];
			sum_white+=sum_b[n-1]-sum_b[i+k-1];
			
			ans=Math.max(sum_black, ans);
			ans=Math.max(sum_white, ans);
			
		}
		System.out.println(ans);
	}
	
}