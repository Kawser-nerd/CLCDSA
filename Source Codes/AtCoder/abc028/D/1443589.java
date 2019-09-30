import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		double N=sc.nextDouble();
		double K=sc.nextDouble();
		
		double ans=0;
		if(K>1 && K<N){
			ans=((K-1)*(N-K)*6+(N-1)*3+1)/(N*N*N);
		}else{
			ans=((N-1)*3+1)/(N*N*N);
		}
		
		System.out.println(ans);
	}
}