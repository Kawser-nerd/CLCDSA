import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		/*
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		int[] bambooLengths = new int[N];
		for (int i = 0; i < N; i++) {
			bambooLengths[i] = sc.nextInt();
		}
		*/
		int A = sc.nextInt();
		int B = sc.nextInt();
		int Q = sc.nextInt();
		long[] AMarks = new long[A];
		long[] BMarks = new long[B];
		long[] QMarks = new long[Q];
		for (int i = 0; i < A; i++) {
			AMarks[i] = sc.nextLong();
		}
		for (int i = 0; i < B; i++) {
			BMarks[i] = sc.nextLong();
		}
		for (int i = 0; i < Q; i++) {
			QMarks[i] = sc.nextLong();
		}
		
		long Alo = AMarks[0];
		long Ahi = AMarks[A-1];
		long Blo = BMarks[0];
		long Bhi = BMarks[B-1];
		for (int i = 0; i < Q; i++) {
			long query = QMarks[i];
			int[] closestA = getClosestIndex(AMarks, query, 0, A-1);
			int[] closestB = getClosestIndex(BMarks, query, 0, B-1);
			//System.out.println("Closest A: " + closestA[0] + ", " + closestA[1]);
			//System.out.println("Closest B: " + closestB[0] + ", " + closestB[1]);
			long min = 0;
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					long distance = Math.abs(AMarks[closestA[k]]-query)+Math.abs(BMarks[closestB[l]]-AMarks[closestA[k]]);
					if (distance < min || min == 0) {
						min = distance;
					}
				}
			}
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					long distance = Math.abs(BMarks[closestB[k]]-query)+Math.abs(AMarks[closestA[l]]-BMarks[closestB[k]]);
					if (distance < min) {
						min = distance;
					}
				}
			}
			System.out.println(min);
		}
    }
	
	public static int[] getClosestIndex(long[] marks, long query, int low, int high) {
		if (query > marks[high]) {
			if (high == marks.length-1) {
				return new int[]{high, high};
			}
			return new int[]{high, high+1};
		} else if (query < marks[low]) {
			if (low == 0) {
				return new int[]{low, low};
			}
			return new int[]{low-1, low};
		}
		int mid = (high+low)/2;
		if (query > marks[mid]) {
			return getClosestIndex(marks, query, mid+1, high);
		} else {
			return getClosestIndex(marks, query, low, mid-1);
		}
	}
  
}