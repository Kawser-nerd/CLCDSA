import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		long sum=0;
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			sum+=a[i];
		}
		long nsum=(long)n*(long)(n+1)/2;
		if(sum%nsum!=0){
			System.out.println("NO");
			return;
		}
		
		long k=sum/nsum;
		
		int[] d=new int[n];
		for(int i=0;i<n;i++){
			if(i==n-1)d[i]=a[0]-a[n-1];
			else d[i]=a[i+1]-a[i];
			
			d[i]-=k;
		}
		
		for(int t=0;t<k;t++){
			for(int i=0;i<n;i++){
				if(d[i]!=0){
					d[i]+=n;
					break;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			if(d[i]!=0){
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		
	}

}