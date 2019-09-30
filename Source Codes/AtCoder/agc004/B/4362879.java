import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashMap;


public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int x = scanner.nextInt();
    int INF = Integer.MAX_VALUE;
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
    }
    int[] b = new int[n];
    Arrays.fill(b, INF);
    long ans = Long.MAX_VALUE;
    for(int magic = 0; magic < n; magic++){
      long s = (long)magic * x;
      for(int i = 0; i < n; i++){
        b[i] = Math.min(b[i], a[(i+n-magic)%n]);
        s += b[i];
      }
      ans = Math.min(ans, s);
    }
    System.out.println(ans);
  }
}