import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		boolean redable[] = new boolean[N];
		int balls[] = new int[N];
		for(int i=0;i<N;++i) balls[i] = 1;
		redable[0] = true;
		
		for(int i=0;i<M;++i){
			int x = sc.nextInt()-1;
			int y = sc.nextInt()-1;
			if(redable[x]) redable[y] = true;
			balls[x]--;
			balls[y]++;
			if(balls[x]==0) redable[x] = false;
		}

		int ans = 0;
		for(int i=0;i<N;++i) if(redable[i]) ans++;
		System.out.println(ans);
		return;
	}
}