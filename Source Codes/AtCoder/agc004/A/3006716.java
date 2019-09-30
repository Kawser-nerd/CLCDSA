import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		long[] hen=new long[3];
		long wa=1;
		for(int i=0; i<3; i++) {
			hen[i]=sc.nextLong();
			wa*=hen[i]%2;
		}

		if(wa==0) {
			System.out.println(0);
		}
		else {
			Arrays.sort(hen);
			System.out.println(hen[0]*hen[1]);
		}
	}
}