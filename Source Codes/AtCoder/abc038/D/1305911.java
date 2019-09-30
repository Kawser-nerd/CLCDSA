import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt();
		int[][] box = new int[N][2];
		for(int i=0;i<N;i++){
			box[i][0]=scan.nextInt();
			box[i][1]=scan.nextInt();
		}

		Arrays.sort(box,new ArraySort());

		final int INF = 1000000000;
		int dp[] = new int[N+1];//dp[i] = ????????i ?????????????
		int dpw[] = new int[N+1];						//???a[i]?????dp[j]<a[i]<=dp[j+1]????dp[j+1]=a[i]
		for(int i=0;i<N+1;i++){
			dp[i]=INF;
			dpw[i]=INF;
		}


		for(int i=0;i<N;i++){//?????????????????????

			int result = Arrays.binarySearch(dp,box[i][1]);
			int insertionPoint = (result>=0) ? result : ~result;
/*				if(insertionPoint>0&&dpw[insertionPoint-1]==box[i][0]){//?????????????
					continue;
			}*/
			dp[insertionPoint] =box[i][1];
			dpw[insertionPoint] =box[i][0];
			}


		for(int i=0;i<N;i++){
			if(dp[i+1]==INF){
				System.out.println(i+1);
				break;
			}
		}


	}

}


class ArraySort implements Comparator<int[]>{
	public int compare(int[] num1,int[] num2){
		if(num1[0]==num2[0]){
			//????????????????????
			return num2[1]-num1[1];
		}
		return num1[0]-num2[0];
	}
}
//O(nlog(n))