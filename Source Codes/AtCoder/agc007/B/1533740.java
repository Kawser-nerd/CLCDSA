import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] p=new int[n];
		for(int i=0;i<n;i++){
			p[i]=sc.nextInt();
		}
		int[] a=new int[n];
		int[] b=new int[n];
		for(int i=0;i<n;i++){
			a[i]=i+1;
			b[i]=n-i;
		}
		for(int i=0;i<n;i++){
			for(int j=p[i];j<=n;j++){
				a[j-1]+=i;
			}
			for(int j=1;j<=p[i];j++){
				b[j-1]+=i;
			}
		}
		
		for(int i=0;i<n-1;i++){
			System.out.print(a[i]+" ");
		}
		System.out.println(a[n-1]);
		for(int i=0;i<n-1;i++){
			System.out.print(b[i]+" ");
		}
		System.out.println(b[n-1]);
	}
	
}