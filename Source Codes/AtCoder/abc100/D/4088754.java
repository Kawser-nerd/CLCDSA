import java.util.Arrays;
import java.util.Scanner;

class Main{


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int m = sc.nextInt();
		long[]x = new long[n];
		long[]y = new long[n];
		long[]z = new long[n];

		for(int i = 0;i < n;i++){
			x[i] = sc.nextLong();
			y[i] = sc.nextLong();
			z[i] = sc.nextLong();

		}

		long[] ppp = new long[n];
		long[] ppm = new long[n];
		long[] pmp = new long[n];
		long[] mpp = new long[n];
		long[] pmm = new long[n];
		long[] mmp = new long[n];
		long[] mpm = new long[n];
		long[] mmm = new long[n];

		for(int i = 0;i < n;i++){
			ppp[i] = x[i] + y[i] + z[i];
		}
		for(int i = 0;i < n;i++){
			ppm[i] = x[i] + y[i] - z[i];
		}
		for(int i = 0;i < n;i++){
			pmp[i] = x[i] - y[i] + z[i];
		}
		for(int i = 0;i < n;i++){
			mpp[i] = (-x[i]) + y[i] + z[i];
		}
		for(int i = 0;i < n;i++){
			pmm[i] = x[i] - y[i] - z[i];
		}
		for(int i = 0;i < n;i++){
			mmp[i] = -x[i] - y[i] + z[i];
		}
		for(int i = 0;i < n;i++){
			mpm[i] = -x[i] + y[i] - z[i];
		}
		for(int i = 0;i < n;i++){
			mmm[i] = -x[i] - y[i] - z[i];
		}
		Arrays.sort(ppp);
		Arrays.sort(ppm);
		Arrays.sort(pmp);
		Arrays.sort(pmm);
		Arrays.sort(mmp);
		Arrays.sort(mpp);
		Arrays.sort(mpm);
		Arrays.sort(mmm);


		long ans = 0l;
		long[] data = new long[8];
		for(int i = 0;i < m;i++){
			data[0] += ppp[n-1-i];
			//			System.out.println("ppp "+ppp[n-1-i]);
		}
		for(int i = 0;i < m;i++){
			data[1] += ppm[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[2] += pmp[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[3] += mpp[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[4] += pmm[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[5] += mmp[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[6] += mpm[n-1-i];
		}
		for(int i = 0;i < m;i++){
			data[7] += mmm[n-1-i];
		}

		Arrays.sort(data);
//		for(int i = 0;i < 8;i++){
//			System.out.println(data[i]);
//		}
		System.out.println(data[7]);

	}

}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}