import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashSet;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] a = new int[3*n];
		for(int i = 0; i < 3 * n; i++){
			a[i] = scanner.nextInt();
		}
		Arrays.sort(a);
		long sum = 0;
		for(int i = 3 * n - 2; i >= n; i -= 2){
			sum += a[i];
		}
		System.out.println(sum);
	}
}