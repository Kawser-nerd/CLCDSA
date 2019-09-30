import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	long N;

	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextLong();
		ArrayList<long[]> down = new ArrayList<long[]>();
		ArrayList<long[]> up   = new ArrayList<long[]>();
		ArrayList<long[]> flat = new ArrayList<long[]>();
		for (int i = 0; i < N; i++) {
			long[] tmp = new long[2];
			long tmp1 = sc.nextLong();
			long tmp2 = sc.nextLong();
			tmp[0] = tmp1;
			tmp[1] = tmp2;
			
			if (tmp1 < tmp2) down.add(tmp);
			else if (tmp1 > tmp2) up.add(tmp);
			else flat.add(tmp);
		}
		long[][] downlist = new long[down.size()][2];
		long[][] uplist = new long[up.size()][2];
		long[][] flatlist = new long[flat.size()][2];

		for (int i = 0; i < down.size(); i++) {
			downlist[i] = down.get(i);
		}
		for (int i = 0; i < up.size(); i++) {
			uplist[i] = up.get(i);
		}
		for (int i = 0; i < flat.size(); i++) {
			flatlist[i] = flat.get(i);
		}
		Arrays.sort(downlist, new Comparator<long[]> () {
			@Override
			public int compare(long[] o1, long[] o2) {
				if (o1[0] == o2[0]) return (int)(o2[1] - o1[1]);
				else return (int)(o1[0] - o2[0]);
			}
		});
		Arrays.sort(uplist, new Comparator<long[]> () {
			@Override
			public int compare(long[] o1, long[] o2) {
				if (o1[1] == o2[1]) return (int)(o2[0] - o1[0]);
				else return (int)(o2[1] - o1[1]);
			}
		});
		
		long max = 0, now = 0;
		for (long[] lst : downlist) {
			if (max < now + lst[0]) max = now + lst[0];
			now += lst[0] - lst[1];
		}
		for (long[] lst : flatlist) {
			if (max < now + lst[0]) max = now + lst[0];
		}
		for (long[] lst : uplist) {
			if (max < now + lst[0]) max = now + lst[0];
			now += lst[0] - lst[1];
		}
		System.out.println(max);
		sc.close();
	}
}