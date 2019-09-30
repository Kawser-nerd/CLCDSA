import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] t = new int[N];
		int all = 0;
		for(int i = 0; i < N; i++){
			t[i] = scanner.nextInt();
			all += t[i];
		}
		int min = 1000;
		for(int i = 0; i < (1<<N); i++){
			int time = 0;
			for(int j = 0; j < N; j++){
				if((1 & (i>>j)) == 1){
					time += t[j];
				}
			}
			int tmp = Math.max(time, all-time);
			if(min > tmp){
				min = tmp;
			}
		}
		System.out.println(min);
	}
}