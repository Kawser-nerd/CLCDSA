import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] c = new int[6];
		for(int i = 0;i < 9;i++) {
			int a = scn.nextInt();
			if(i < 3) {
				c[2*i]+=a;
				c[2*i+1] += a;
			}else{
				if(i == 3) {
					c[2]+=a;
					c[4]+=a;
				}
				if(i==4) {
					c[0]+=a;
					c[5]+=a;
				}
				if(i == 5) {
					c[1]+=a;
					c[3]+=a;
				}
				if(i == 6) {
					c[3]+=a;
					c[5]+=a;
				}
				if(i == 7) {
					c[1]+=a;
					c[4]+=a;
				}
				if(i == 8) {
					c[0]+=a;
					c[2]+=a;
				}
			}
		}
		boolean ans = true;
		for(int i = 0;i < 6;i++) {
			ans &= (c[i]==c[0]);
		}
		System.out.println(ans?"Yes":"No");
	}

}