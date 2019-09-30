import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int ans = 0;
		for(int i = 1; i < k; i++){
			for(int j = i+1; j <= k; j++){
				if(i%2!=j%2){
					ans++;
				}
			}
		}
		System.out.print(ans);
	}
}