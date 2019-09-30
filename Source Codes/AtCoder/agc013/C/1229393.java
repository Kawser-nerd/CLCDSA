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
		boolean[] w = new boolean[N];
		ArrayList<Integer> cw = new ArrayList<>();
		ArrayList<Integer> ccw = new ArrayList<>();
		for(int i=0; i<N; i++) {
			x[i] = sc.nextInt();
			w[i] = sc.nextInt()==1;
			if(w[i])
				cw.add(x[i]);
			else
				ccw.add(x[i]);
		}
		Collections.reverse(cw);
		
		if(cw.size()==0 || ccw.size()==0) {
			for(int i=0; i<N; i++) {
				pw.println((x[i]+(w[i]? T%L : L-(T%L)))%L);
			}
		} else {
			int[] pos = new int[N];
			for(int i=0; i<N; i++)
				pos[i] = (int)((x[i]+(w[i]? T%L : L-(T%L)))%L);
			Arrays.sort(pos);
			
			long cnt = 0;
			for(int ccwx : ccw) {
				long dis = (ccwx-cw.get(0)+L)%L;
				cnt = (cnt + (2*T + L-dis-1)/L)%N;
			}
			
			int a = Arrays.binarySearch(pos, (int)((cw.get(0)+T)%L));
			if(a>0 && pos[a-1]==pos[a])
				a--;
			int idx = (a - Arrays.binarySearch(x, cw.get(0)) - (int)cnt + N + N)%N;
			
			for(int i=0; i<N; i++)
				pw.println(pos[(idx+i)%N]);
		}
		
		sc.close();
		pw.close();
	}
}