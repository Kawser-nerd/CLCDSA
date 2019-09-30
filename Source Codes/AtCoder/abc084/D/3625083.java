import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		int Q = sc.nextInt();
		
		int[] pl = new int[100001];
		for(int i=3;i<=100000;i++){
			if(isPrime(i)&&isPrime((i+1)/2)){
				pl[i] = pl[i-1] + 1;
			}else{
				pl[i] = pl[i-1];
			}
		}
		for(int i=0;i<Q;i++){
			int l = sc.nextInt();
			int r = sc.nextInt();
			System.out.println(pl[r]-pl[l-1]);
		}
	}

	private static boolean isPrime(int n) {
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
	
}