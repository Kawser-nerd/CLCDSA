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
    int[] a = new int[n];
    int count = 0;
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
      if(a[i] % 2 == 1){
        count++;
      }
    }
    if(count%2 == 1){
      System.out.println("NO");
    }else{
      System.out.println("YES");
    }
  }
}