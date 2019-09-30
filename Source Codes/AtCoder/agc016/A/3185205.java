import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		String S = sc.next();
		int L = S.length();
		Boolean[] B = new Boolean[L+2];
		B[L+1] = false;
		int time = 0;
		int last = 0;
		int min = 500;
		for(char i='a';i<='z';i++) {
			time = 0;
			Boolean C = false;
			for(int j=0;j<L;j++) {
				if(S.charAt(j) == i) {
					B[j] = true;
					last = j;
				}else {
					B[j] = false;
				}
			}
			while(true){
				C = true;
				for(int j=0;j<=last;j++) {
					if(!B[j]) {
						C = false;
					}
				}
				if(C||time==100) {
					break;
				}else {

					for(int j=0;j<last;j++) {
						if(B[j+1]) {
							B[j] = true;
						}
					}
					time++;
				}
			}
			time = Math.max(time, L-last-1);
			min = Math.min(min, time);
		}
		System.out.println(min);
	}
}