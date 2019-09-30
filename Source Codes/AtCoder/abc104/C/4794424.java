import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		int G = sc.nextInt()/100;
		int[] p = new int[D+1];
		int[] c = new int[D+1];
		int[] score = new int[D+1];
		for(int i = 1; i <= D; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt()/100;
			score[i] = i * p[i] + c[i];
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < 1 << D; i++) {
			int max = 0, num = 0, value = 0;
			for(int j = 0; j < D; j++) {
				if((1 & (i >> j)) == 1) {
					num += p[j+1];
					value += score[j+1];
				}
				else
					max = j+1;
			}
			if(value < G) {
				for(int j = 0; j < p[max]-1; j++) {
					value += max;
					num += 1;
					if(value >= G) 
						break;
				}
			}
			if(value >= G)
				ans = Math.min(ans, num);
		}
		System.out.println(ans);
	}

}