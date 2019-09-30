import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] x = new int[N];
		int[] y = new int[N];
		for(int i = 0; i < N; i++){
			x[i] = scanner.nextInt();
			y[i] = scanner.nextInt();
		}
		long countV = 0;
		long countA = 0;
		long all = N * 1L * (N-1) * (N-2) / 6;
		double eps = 1e-10;
		for(int o = 0; o < N; o++){
			ArrayList<Double> angles = new ArrayList<Double>();
			for(int i = 0; i < N; i++){
				if(o == i) continue;
				angles.add(Math.atan2(y[i]-y[o], x[i]-x[o]));
				angles.add(Math.atan2(y[i]-y[o], x[i]-x[o]) + 2 * Math.PI);
			}
			Collections.sort(angles);
			for(int i = 0; i < N-1; i++){
				double ang = angles.get(i);
				countV += upperBound(angles, ang + Math.PI / 2 + eps) - lowerBound(angles, ang + Math.PI / 2 - eps);
				countA += lowerBound(angles, ang + Math.PI - eps) - upperBound(angles, ang + Math.PI / 2 + eps);
			}
		}
		System.out.println(all-countV-countA + " " + countV + " " + countA);
	}
	public static <T extends Number> int lowerBound(final List<T> lis, final T value) {
			 int low = 0;
			 int high = lis.size();
			 int mid;

			 while (low < high) {
					 mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
					 if (lis.get(mid).doubleValue() < value.doubleValue()) {
							 low = mid + 1;
					 } else {
							 high = mid;
					 }
			 }
			 return low;
	 }
	 public static <T extends Number> int upperBound(final List<T> lis, final T value) {
			 int low = 0;
			 int high = lis.size();
			 int mid;
			 while (low < high) {
					 mid = ((high - low) >>> 1) + low;
					 if (lis.get(mid).doubleValue() < value.doubleValue()) {
							 low = mid + 1;
					 } else {
							 high = mid;
					 }
			 }
			 return low;
	 }
	 public static int lowerBound(final int[] arr, final int value) {
			 int low = 0;
			 int high = arr.length;
			 int mid;

			 while (low < high) {
					 mid = ((high - low) >>> 1) + low;
					 if (arr[mid] < value) {
							 low = mid + 1;
					 } else {
							 high = mid;
					 }
			 }
			 return low;
	 }
}