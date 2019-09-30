import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int xa[] = new int[n];
		int ya[] = new int[m];
		for(int i = 0; i < n; i++){
			xa[i] = sc.nextInt();
		}
		for(int i = 0; i < m; i++){
			ya[i] = sc.nextInt();
		}
		boolean ans = false;
		for(int i = x+1; i <= y; i++){
			boolean flag = false;
			for(int j = 0; j < n; j++){
				if(xa[j] >= i){
					flag = true;
				}
			}
			for(int j = 0; j < m; j++){
				if(ya[j] < i) flag = true;
			}
			if(flag == false){
				ans = true;
				break;
			}
		}
		if(ans){
			System.out.print("No War");
		}else{
			System.out.print("War");
		}
	}
}