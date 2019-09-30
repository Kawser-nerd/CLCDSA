import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] a = new int[N];
		for(int i=0; i<N; i++)
			a[i] = sc.nextInt();
		Arrays.sort(a);
		
		int min = -1;
		int max = N;
		while(min+1 < max) {
			int mid = (min+max)/2;
			boolean[] visited = new boolean[K];
			visited[0] = true;
			for(int i=0; i<N; i++) {
				if(i==mid)
					continue;
				for(int j=K-1; j>=0; j--)
					if(visited[j] && j+a[i]<K)
						visited[j+a[i]] = true;
			}
			boolean ok = false;
			for(int i=K-1; i+a[mid]>=K && i>=0; i--)
				if(visited[i]) {
					ok = true;
					break;
				}
			if(ok) {
				max = mid;
			} else {
				min = mid;
			}
		}
		
		System.out.println(max);
		
		sc.close();
	}
}