import java.util.*;

public class CSmall {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int T = sc.nextInt();
		for(int caseID = 1; caseID <= T; caseID++){
			int K = sc.nextInt();
			int n = sc.nextInt();
			int[] ds = new int[n];
			for(int i = 0; i < n; i++){
				ds[i] = sc.nextInt();
			}
			boolean[] visited = new boolean[K];
			int[] cards = new int[K];
			int iter = 0;
			for(int i = 1; i <= K; i++){
				int cnt = 0;
				int next = (i - 1) % (K - i + 1);
				while(true){
					if(iter == K) iter = 0;
					if(!visited[iter]){
						if(cnt == next){
							visited[iter] = true;
							cards[iter] = i;
							cnt++;
							iter++;
							break;
						}
						else{
							cnt++;
							iter++;
						}
					}
					else{
						iter++;
					}
				}
			}
			System.out.printf("Case #%d:", caseID);
			for(int i = 0; i < n; i++){
				System.out.printf(" %d", cards[ds[i] - 1]);
			}
			System.out.printf("%n");
		}
	}
}
