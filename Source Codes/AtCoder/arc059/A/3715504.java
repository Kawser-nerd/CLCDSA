import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Main {
	public static void main(String args[]){
		    Scanner sc = new Scanner(System.in);	
			
			int n = sc.nextInt();
			int[] ar = new int[n];
			int mincost = Integer.MAX_VALUE;
			int sumcost = 0;
			for (int i = 0; i < n; i++) {
				ar[i] = sc.nextInt();
			}
			for (int i = -100; i <= 100; i++) {
				for (int j = 0; j < n; j++) {
					sumcost = sumcost + Math.abs(ar[j]-i)*Math.abs(ar[j]-i);
				}
				if (sumcost < mincost) {
					mincost = sumcost;
				}
				sumcost = 0;
			}
			System.out.println(mincost);


		    sc.close(); }

	public static boolean isEven(int n ) {
		if (n % 2 == 0) {
			return true;
		}else{
			return false;
		}
	}
}