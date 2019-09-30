import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		long[] aArray = new long[n];
		long[] bArray = new long[n];

		for (int i=0;i<n;i++) {
			aArray[i]=sc.nextLong();
		}
		for (int i=0;i<n;i++) {
			bArray[i]=sc.nextLong();
		}

		long [] bitSum = new long [32];
		for (int i=0;i<n;i++) {
			for (int j=0;j<32;j++) {
				bitSum[j] += ((aArray[i] >> j) % 2)*n;
				bitSum[j] += ((bArray[i] >> j) % 2)*n;
			}
		}

		long [] aModArray = new long[n];
		long [] bModArray = new long[n];

		for (int i=0;i<32;i++) {

			final int k = i;
			for (int j=0;j<n;j++) {
				aModArray[j]=aArray[j] % (1L << i);
				bModArray[j]=bArray[j] % (1L << i);
			}

			Arrays.sort(bModArray);

			for (long a : aModArray) {
				bitSum[i] += (n - firstBinarySearch(bModArray, (1L << (i)) - a));
			}
		}
		long ans = 0;

		for (int i=0;i<32;i++) {
			if (bitSum[i]%2 == 1) {
				ans += (1L<<i);
			}
		}

		System.out.println(ans);
	}

	static  int firstBinarySearch (long[] array, long v) {
		//return the index of the first object larger than or equal to v
		//n if doesn't exist
		int n =array.length;
		int min = 0;
		int max = n-1;

		if (array[n-1] < v) {
			return n;
		}

		if (array[0] >= v) {
			return 0;
		}

		while (max > min + 1) {
			int mid = min+(max-min)/2;
			if (array[mid] >= v) {
				max = mid;
			} else {
				min = mid;
			}
		}

		return max;
	}

}