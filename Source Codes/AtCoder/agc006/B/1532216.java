import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		n=2*n-1;
		int x=sc.nextInt();
		if(n==1){
			if(x==1){
				System.out.println("Yes");
				System.out.println(1);
				return;
			}else{
				System.out.println("No");
				return;
			}
		}
		if(n==3){
			if(x==2){
				System.out.println("Yes");
				System.out.println(1);
				System.out.println(2);
				System.out.println(3);
				return;
			}else{
				System.out.println("No");
				return;
			}
		}
		if(x==1 || x==n){
			System.out.println("No");
			return;
		}else{
			System.out.println("Yes");
			int count=0;
			for(int i=1;i<=n;i++){
				if(count==(n-5)/2){
					if(x-2==0){
						System.out.println(x+2);
						System.out.println(x-1);
						System.out.println(x);
						System.out.println(x+1);
						System.out.println(x+3);
					}else if(x+2==n+1){
						System.out.println(x-3);
						System.out.println(x-1);
						System.out.println(x);
						System.out.println(x+1);
						System.out.println(x-2);
					}else{
						System.out.println(x+2);
						System.out.println(x-1);
						System.out.println(x);
						System.out.println(x+1);
						System.out.println(x-2);
					}
					count+=5;
				}
				if(x-2==0 && i==x+3)continue;
				if(x+2==n+1 && i==x-3)continue;
				if(i>=x-2 && i<=x+2)continue;
				else{
					System.out.println(i);
					count++;
				}
			}
		}
	}
	
}