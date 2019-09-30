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
		long n = scanner.nextLong();
		long a = scanner.nextLong();
		long b = scanner.nextLong();
		long ans = (b-a)*(n-2)+1;
		if(a > b){
			System.out.println(0);
		}else if(a == b){
			System.out.println(1);
		}else if(a < b){
			if(n >= 2){
				System.out.println(ans);
			}else if(n == 1){
				System.out.println(0);
			}
		}
	}
}