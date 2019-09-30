import java.util.Scanner;

/**
 * http://abc019.contest.atcoder.jp/tasks/abc019_4
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		
		int max = 0;
		int maxNode = 0;
		for(int e=2; e<=N; e++){
			String question = String.format("? %d %d", 1, e);
			System.out.println(question);
			int d = sc.nextInt();
			if(max<d){
				maxNode = e;
				max = d;
			}
		}
		
		int ans = 0;	
		for(int e=1; e<=N; e++){
			if(e==maxNode){
				continue;
			}
			String question = String.format("? %d %d", maxNode, e);
			System.out.println(question);
			int d = sc.nextInt();
			ans = Math.max(ans, d);
		}
		
		System.out.println("! "+ ans);
		
		sc.close();

	}

}