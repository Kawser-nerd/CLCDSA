import java.util.*;
import java.math.*;
class Main{
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 1; t <= tests; t++){
			int p = sc.nextInt(), q = sc.nextInt();
			int [] cells = new int[q];
			for(int i = 0; i < q; i++){
				cells[i] = sc.nextInt();
			}
			int [] nums = new int[q + 1];
			nums[0] = cells[0] - 1;
			for(int i = 1; i < q; i++){
				nums[i] = cells[i] - cells[i-1] - 1;
			}
			nums[q] = p - cells[q-1];
			int [][] fromto = new int[q + 1][q + 1];
			
			for(int start = 0; start <= q; start++){
				//fromto[start][start] = nums[start];
			}
			
			for(int d = 1; d <= q; d++){
				for(int start = 0; start <= q-d; start++){
					int min = p * p;
					int all = 0;
					for(int i = 0; i <=d; i++){
						all += nums[start+i];
					}
					all+=d-1;
					for(int i = 0; i < d; i++){
						int sum = all + fromto[start][start+i] + fromto[start+i+1][start+d];
						if(sum < min){
							min = sum;
						}
					}
					
					fromto[start][start + d] = min;
				}
			}
			for(int i = 0; i <= q; i++){
				for(int j = i; j <= q; j++){
					//System.err.printf("fromto[%d][%d] = %d\n", i, j, fromto[i][j]);
				}
			}

			System.err.println(t);
			System.out.printf("Case #%d: %d\n", t, fromto[0][q]);
		}
	}

}
