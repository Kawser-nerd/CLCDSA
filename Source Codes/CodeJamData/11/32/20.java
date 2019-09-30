import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B implements Runnable {

	final String FILENAME = "B-large";
//	final String FILENAME = "B-small";

	
	public void solve() throws IOException {
		Scanner in = new Scanner(new File(FILENAME + ".in"));
		PrintWriter out = new PrintWriter(new File(FILENAME + ".out"));

		int testn = in.nextInt();
		for (int test = 0; test < testn; test++) {
//			Each contains integers, L, t, N and C, followed by C integers ai, all separated by spaces. 
			int L = in.nextInt();
			long t = in.nextLong();
			int N = in.nextInt();
			int C = in.nextInt();
			
			int[] arr = new int[C];
			int max = -1;
			int maxPrev = -1;
			for (int i=0; i<C; i++) {
				arr[i] = in.nextInt();
				if (arr[i] > max) {
					if (max != -1) {
						maxPrev = max;
					}
					max = arr[i];
				}
			}
			
			long sum = 0;
			long currentTime = 0;
			List<Long> gList = new ArrayList<Long>();
			for (int i=0; i<N; i++) {
				long len = 0;
				if (i < C) {
					len = arr[i];
				}
				else {
					int temp = i%C;
					len = arr[temp];
				}
				
				if (t < currentTime) {
					gList.add(-len);
				}
				else {
					if (t < (currentTime + len*2)) {
						long dif = t - currentTime;
						gList.add( -((len*2) - dif)/2);
					}
				}
				
//				lList.add(len);
				sum = sum + len;
				currentTime = sum*2;
			}
			
//			int time = sum*2;
			
			Collections.sort(gList);
			for (int i=0; i<L; i++) {
				if (i < gList.size()) {
					long L1 = gList.get(i);
					currentTime = currentTime + L1;
				}
			}

			out.println("Case #" + (test + 1) + ": " + currentTime);
		}

		in.close();
		out.close();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			throw new AssertionError();
		}
	}

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

}
