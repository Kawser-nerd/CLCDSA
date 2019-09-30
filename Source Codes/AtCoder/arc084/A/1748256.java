import java.util.*;

// ARC 84-A
// https://beta.atcoder.jp/contests/arc084/tasks/arc084_a

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		
		ArrayList<Integer> A = new ArrayList<Integer>();
		ArrayList<Integer> B = new ArrayList<Integer>();
		ArrayList<Integer> C = new ArrayList<Integer>();
		
		TreeSet<Integer> aSet = new TreeSet<Integer>();
		TreeSet<Integer> bSet = new TreeSet<Integer>();
		TreeSet<Integer> cSet = new TreeSet<Integer>();
		
		for (int i = 0; i < N; i++) {
			int n = in.nextInt();
			A.add(n);
		}
		for (int i = 0; i < N; i++) {
			int n = in.nextInt();
			B.add(n);
			bSet.add(n);
		}
		for (int i = 0; i < N; i++) {
			int n = in.nextInt();
			C.add(n);
			cSet.add(n);
		}
		
		A.sort(null);
		B.sort(null);
		C.sort(null);
		
		long[] temp = new long[N];
		for (int i = 0; i < N; i++) {
			Integer c = cSet.higher(B.get(i));
			
			if (c != null) {
				int index = binarySearch3(C, c);
				temp[i] = (N - index);
			}
		}
		
		for (int i = N - 2; i >= 0; i--) {
			temp[i] += temp[i + 1];
		}
		
		long answer = 0;
		for (int i = 0; i < A.size(); i++) {
			Integer b = bSet.higher(A.get(i));
			
			if (b != null) {
				int index = binarySearch3(B, b);
				answer += temp[index];
			}
		}
		System.out.println(answer);
	}
	
	public static int binarySearch1(int[] arr, int n) {
		int low = 0;
		int high = arr.length - 1;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			
			if (arr[mid] == n && (mid == arr.length - 1 || arr[mid + 1] != arr[mid])) {
				return mid;
			} else if (arr[mid] > n) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;
	}
	
	public static int binarySearch2(int[] arr, int n) {
		int low = 0;
		int high = arr.length - 1;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			
			if (arr[mid] == n && (mid == 0 || (mid > 0 && arr[mid - 1] != arr[mid]))) {
				return mid;
			} else if (arr[mid] < n) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	}
	
	public static int binarySearch3(ArrayList<Integer> arr, int n) {
		int low = 0;
		int high = arr.size() - 1;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			
			if (arr.get(mid) == n && (mid == 0 || (mid > 0 && !arr.get(mid - 1).equals(arr.get(mid))))) {
				return mid;
			} else if (arr.get(mid) < n) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	}
}