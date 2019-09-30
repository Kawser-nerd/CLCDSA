import java.util.Scanner;

/**
 * http://abc013.contest.atcoder.jp/tasks/abc013_4
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		final int D = sc.nextInt();
		final int[] a = new int[M];
		for(int i=0; i<M; i++) a[i] = sc.nextInt()-1;
		sc.close();
		
		int[] once = new int[N];
		for(int i=0; i<N; i++) once[i] = i;
		for(int m=0; m<M; m++){
			int t = once[a[m]];
			once[a[m]] = once[a[m]+1];
			once[a[m]+1] = t;
		}
		
		int[] intervel = new int[N];
		int[] ans = new int[N];
		for(int i=0; i<N; i++){
			intervel[once[i]] = i;
			ans[i] = i;
		}

		for( int i=D; i>0; i=i/2){
			if(i%2==1) for(int j=0; j<N; j++) ans[j] = intervel[ans[j]];
			int[] tmp = new int[N];
			for(int j=0; j<N; j++) tmp[j] = intervel[j];
			for(int j=0; j<N; j++) intervel[j] = tmp[tmp[j]];
		}
		
		for(int i=0; i<N; i++) System.out.println(ans[i]+1);

	}

}