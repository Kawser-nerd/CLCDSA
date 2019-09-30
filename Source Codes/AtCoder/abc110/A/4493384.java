import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		Integer[]x=new Integer[3];
		for(int i=0;i<3;i++) {
			x[i]=sc.nextInt();
		}
		Arrays.sort(x,Collections.reverseOrder());
		System.out.println(x[0]*10+x[1]+x[2]);
		
	}
}