import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		Random r = new Random();
		int N = sc.nextInt();
		long L = sc.nextLong();
		long T = sc.nextLong();
		int[] x = new int[N];
		boolean[] cw = new boolean[N];
		for(int i=0; i<N; i++) {
			x[i] = sc.nextInt();
			cw[i] = sc.nextInt()==1;
		}

		int[] pos = new int[N];
		for(int i=0; i<N; i++)
			pos[i] = (int)((x[i]+(cw[i] ? T%L : L-(T%L)))%L);
		Arrays.sort(pos);
			
		long cnt = 0;
		for(int i=1; i<N; i++) {
			if(cw[i]!=cw[0]) {
				long dis = ((x[i]-x[0])*(cw[0] ? 1 : -1)+L)%L;
				cnt = (cnt + (2*T + L-dis-1)/L)%N;
			}
		}
			
		int a = Arrays.binarySearch(pos, (int)((x[0]+(T%L)*(cw[0] ? 1 : -1) + L)%L));
		if(cw[0] && a>0 && pos[a-1]==pos[a])
			a--;
		if(!cw[0] && a<N-1 && pos[a+1]==pos[a])
			a++;
		int idx = (int)((a + cnt*(cw[0] ? -1 : 1) + N)%N);
		
		for(int i=0; i<N; i++)
			pw.println(pos[(idx+i)%N]);
		
		sc.close();
		pw.close();
	}
}