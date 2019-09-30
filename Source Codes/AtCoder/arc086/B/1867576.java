import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static char c;

	public static void main(String[] args) throws Exception {
		int k = sc.nextInt();
		int[] arr = new int[k];
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		int maxIdx = -1;
		int minIdx = -1;
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
			if (arr[i] > max) {
				max = arr[i];
				maxIdx = i;
			}
			if (arr[i] < min) {
				min = arr[i];
				minIdx = i;
			}
		}
		System.out.println(k*2-1);
		if(Math.abs(min)>max){
			for(int i=0;i<k;i++){
				System.out.println((minIdx+1)+" "+(i+1));
			}
			for(int i=k;i>1;i--){
				System.out.println(i+" "+(i-1));
			}
		}
		else{
			for(int i=0;i<k;i++){
				System.out.println((maxIdx+1)+" "+(i+1));
			}
			for(int i=1;i<k;i++){
				System.out.println(i+" "+(i+1));
			}
		}

	}

}