import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		
		Scanner in = new Scanner(System.in);
		
		int[] primeNumList = new int[100000];
		primeNumList[0] = -1;
		for(int i = 0; i < primeNumList.length; i++) {
			if(primeNumList[i] == -1) continue;
			for(int j = i + i + 1; j < primeNumList.length; j += (i + 1)) {
				primeNumList[j] = -1;
			}
		}
		
		/*
		for(int i = 0; i < 20; i++) {
			if(primeNumList[i] != -1) System.out.print((i + 1) + " ");
		}
		System.out.println();
		*/
		
		int[] susum = new int[50000];
		susum[0] = 0;
		susum[1] = 1;		
		for(int i = 2; i < susum.length; i++) {
			susum[i] = susum[i-1];
			if(primeNumList[2 * i] != -1 && primeNumList[i] != -1) susum[i]++;
		}
		
		/*
		for(int i = 0; i < 10; i++) {
			System.out.print(susum[i] + " ");
		}
		System.out.println();
		*/
		
		
		int Q = in.nextInt();
		
		for(int i = 0; i < Q; i++) {
			int L = in.nextInt();
			int R = in.nextInt();
			if(L == 1) System.out.println(susum[(R - 1) / 2]);
			else System.out.println(susum[(R - 1) / 2] - susum[((L - 1) / 2) - 1]);
		}
	}
}