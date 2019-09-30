import java.util.*;
import java.util.stream.IntStream;

public class Main {


	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N =sc.nextInt();
		final int M = sc.nextInt();
		boolean[][] edges = new boolean[N][N];
		for (int i=0; i<M; i++){
			int from = sc.nextInt() -1;
			int to = sc.nextInt() - 1;
			edges[from][to] = edges[to][from] = true;
		}
		int [] path = IntStream.range(0, N).toArray();
		int count =0;
		do {
			if(path[0] !=0){
				continue;
			}
			boolean goodPath = true;
			for(int i=0; i<path.length-1; i++){
				if(!edges[path[i]][path[i+1]]){
					goodPath = false;
					break;
				}
			}
			if(goodPath){
				count +=1;
			}
		} while (nextPermutation(path));

		System.out.println(count);

		sc.close();
	}
	private boolean nextPermutation(int [] array) {
		int n = array.length;
		int k = n - 1;

		while (k > 0 && array[k] < array[k - 1]) {
			k--;
		}
		if (k == 0) {
			return false;
		}
		k -= 1;
		int l = n - 1;
		while (l > k && array[l] < array[k]) {
			l--;
		}
		int tmp;
		tmp = array[k];
		array[k] = array[l];
		array[l] = tmp;
		for (int i = k + 1, j = array.length - 1; i < j; i++, j--) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		return true;
	}

}