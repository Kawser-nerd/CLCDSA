import java.util.Arrays;
import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[] ar=new int[3];
		int[] moto=new int[3];
		for(int i=0; i<3; i++) {
			ar[i]=sc.nextInt();
			moto[i]=ar[i];
		}
		Arrays.sort(ar);
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				if(moto[i]==ar[j]) {
					System.out.println(3-j);
				}
			}
		}
	}
}