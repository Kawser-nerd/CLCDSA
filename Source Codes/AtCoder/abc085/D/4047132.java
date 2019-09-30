import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int H = sc.nextInt();
		long[] a = new long[N];
		long[] b = new long[N];
		long A = 0;
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			b[i] = sc.nextLong();
			A = Math.max(A, a[i]);
		}
		sc.close();
		List<Data> list = new ArrayList<Data>();
		for(int i = 0; i < N; i++) {
			if(b[i] > A) {
				list.add(new Data(a[i], b[i]));
			}
		}
		Collections.sort(list, new MyComparator());
		long sum = 0;
		int l = list.size();
		long cnt = 0;
		for(int i = l - 1; i >= 0; i--) {
			sum += list.get(i).b;
			cnt++;
			if(sum >= H) {
				System.out.println(cnt);
				System.exit(0);
			}
		}
		long res = H - sum;
		cnt += (res + A - 1) / A;
		System.out.println(cnt);
	}
	static class Data{
		long a, b;
		public Data(long a, long b) {
			this.a = a;
			this.b = b;
		}
	}
	static class MyComparator implements Comparator<Data>{
		@Override
        public int compare(Data d1, Data d2) {
			if(d1.b < d2.b) {
				return -1;
			}else if(d1.b == d2.b) {
				return 0;
			}else {
				return 1;
			}
		}
	}
}