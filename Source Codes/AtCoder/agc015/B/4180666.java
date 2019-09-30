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
		String s = scanner.next();
		int n = s.length();
		char[] c = new char[n];
		for(int i = 0; i < n; i++){
			c[i] = s.charAt(i);
		}
		long ans = 0;
		for(int i = 0; i < n; i++){
			if(i == 0 || i == n-1){
				ans += n - 1;
			}else{
				if(c[i] == 'U'){
					ans += n + i - 1;
				}else if(c[i] == 'D'){
					ans += 2 * n - i - 2;
				}
			}
		}
		System.out.println(ans);
	}
}