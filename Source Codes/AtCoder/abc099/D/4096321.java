import java.util.ArrayList;
import java.util.Scanner;

class Main{

	static int ans = Integer.MAX_VALUE;
	static int C;
	static int[][] d;
	static ArrayList<Integer> zero;
	static ArrayList<Integer> one;
	static ArrayList<Integer> two;
	static int[][]memo;




	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		C = sc.nextInt();
		d = new int[C][C];
		for(int i = 0;i < C;i++){
			for(int j = 0;j < C;j++){
				d[i][j] = sc.nextInt();
			}
		}
		int[][] c = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				c[i][j] = sc.nextInt()-1;
			}
		}	
		zero = new ArrayList<Integer>();
		one = new ArrayList<Integer>();
		two = new ArrayList<Integer>();

		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if((i + 1 + j + 1)%3 == 0){
					zero.add(c[i][j]);
				}else if((i + 1 + j + 1)%3 == 1){
					one.add(c[i][j]);
				}else{
					two.add(c[i][j]);
				}
			}
		}	
		//		System.out.println("zero");
		//		for(int i = 0;i < zero.size();i++){
		//			System.out.println(zero.get(i));
		//		}
		//		System.out.println("one");
		//		for(int i = 0;i < one.size();i++){
		//			System.out.println(one.get(i));
		//		}
		//		System.out.println("two");
		//		for(int i = 0;i < two.size();i++){
		//			System.out.println(two.get(i));
		//		}
		memo = new int[3][C];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < C;j++){
				if(i == 0){
					for(int k = 0;k < zero.size();k++){
						memo[i][j] += d[zero.get(k)][j];
					}
				}else if(i == 1){
					for(int k = 0;k < one.size();k++){
						memo[i][j] += d[one.get(k)][j];
					}

				}else{
					for(int k = 0;k < two.size();k++){
						memo[i][j] += d[two.get(k)][j];
					}
				}
			}

		}

		boolean[] used = new boolean[C];
		dfs(0, 0, zero, used);
		System.out.println(ans);


	}
	static void dfs(int p,int sum,ArrayList<Integer> data,boolean[] used){
		if(sum > ans){
			return;
		}
		if(p == 3){
			ans = Math.min(ans, sum);
			return;
		}
		for(int color = 0;color < C;color++){
			int sub = 0;
			if(used[color] != true){
				used[color] = true;
				sub = memo[p][color];
//				for(int i = 0;i <data.size();i++){
//					sub += d[data.get(i)][color];
//				}
				if(p == 0){
					dfs(p+1, sum+sub, one,used);
				}else if(p == 1){
					dfs(p+1, sum+sub, two,used);	
				}else{
					dfs(p+1, sum+sub, two,used);	
				}
				used[color]  = false;
			}
		}

	}

}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}