import java.util.*;

public class A {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int n = Integer.parseInt(sc.nextLine());
		for(int id = 1; id <= n; id++){
			int s = Integer.parseInt(sc.nextLine());
			String[] engines = new String[s];
			for(int i = 0; i < s; i++) engines[i] = sc.nextLine();
			int q = Integer.parseInt(sc.nextLine());
			String[] queries = new String[q];
			for(int i = 0; i < q; i++) queries[i] = sc.nextLine();
			int[][] table = new int[q + 1][s];
			for(int i = 1; i <= q; i++) Arrays.fill(table[i], Integer.MAX_VALUE);
			for(int i = 0; i < q; i++){
				for(int j = 0; j < s; j++){
					if(table[i][j] < Integer.MAX_VALUE){
						for(int k = 0; k < s; k++){
							if(!queries[i].equals(engines[k])){
								table[i + 1][k] = Math.min(table[i][j] + (j == k ? 0 : 1) , table[i + 1][k]);
							}
						}
					}
				}
			}
			int res = Integer.MAX_VALUE;
			for(int j = 0; j < s; j++){
				res = Math.min(table[q][j], res);
			}
			if(res == Integer.MAX_VALUE) throw new RuntimeException();
			System.out.printf("Case #%d: %d%n", id, res);
		}
	}
}
