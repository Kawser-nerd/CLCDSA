import java.util.*;

public class Main {
	
	public static long getCombinations(int num) {
		return ((long)num)*(num-1)/2;
	}
	
	public static int getRoot(int[][] unionArray, int index) {
		if (unionArray[index][0] == index) {
			return index;
		}
		return getRoot(unionArray, unionArray[index][0]);
	}
	
	public static int getSize(int[][] unionArray, int index) {
		if (unionArray[index][0] == index) {
			return unionArray[index][1];
		}
		return getSize(unionArray, unionArray[index][0]);
	}
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		// First position stores the parent of island i, where i = index of the position
		// Second position stores the size of the subset rooted at this island
		int[][] unionArray = new int[N][2];
		long[] inconvenience = new long[M];
		int[][] edges = new int[M][2];
		
		inconvenience[M-1] = getCombinations(N);
		
		for (int i = 0; i < N; i++) {
			unionArray[i][0] = i;
			unionArray[i][1] = 1;
		}
		
		for (int i = 0; i < M; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			edges[i][0] = A-1;
			edges[i][1] = B-1;
		}
		
		for (int i = M-1; i > 0; i--) {
			int A = edges[i][0];
			int B = edges[i][1];
			int rootA = getRoot(unionArray, A);
			int rootB = getRoot(unionArray, B);
			unionArray[A][0] = rootA;
			unionArray[B][0] = rootB;
			long convenience = 0;
			if (rootA != rootB) {
				int sizeA = unionArray[rootA][1];
				int sizeB = unionArray[rootB][1];
				if (rootA < rootB) {
					unionArray[rootB][0] = rootA;
					unionArray[rootA][1] += sizeB;
				} else {
					unionArray[rootA][0] = rootB;
					unionArray[rootB][1] += sizeA;
				}
				convenience += getCombinations(sizeA+sizeB) - getCombinations(sizeA) - getCombinations(sizeB);
			}
			inconvenience[i-1] = inconvenience[i] - convenience;
		}
		
		for (long inc : inconvenience) {
			System.out.println(inc);
		}
    }
  
}