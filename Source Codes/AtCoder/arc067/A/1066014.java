import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		
		if(n<3){
			System.out.println(n);
			return;
		}
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(2);
		for(int i=3; i<=n; i++){
			boolean b = true;
			for(int j=0; j<list.size(); j++){
				if(i % list.get(j) == 0){
					b = false;
					break;
				}
			}
			if(b){
				list.add(i);
			}
		}
		
		long[][] num = new long[n][list.size()];
		for(int i=1; i<=n; i++){
			int x = i;
			for(int j=0; j<list.size(); j++){
				while(x % list.get(j) == 0){
					num[i-1][j]++;
					x /= list.get(j);
				}
			}
		}
		long[] sum = new long[list.size()];
		for(int i=1; i<=n; i++){
			for(int j=0; j<list.size(); j++){
				sum[j] += num[i-1][j];
			}
		}
		long ans = 1;
		for(int i=0; i<list.size(); i++){
			if(sum[i] != 0){
				ans *= sum[i] + 1L;
			}
			if(ans >= 1000000007L){
				ans %= 1000000007L;
			}
		}
		System.out.println(ans);
	}

}