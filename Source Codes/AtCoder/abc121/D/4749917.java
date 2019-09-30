import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner sc = new Scanner(System.in);
		String[] line = sc.nextLine().split(" ");
		long A = Long.parseLong(line[0]);
		long B = Long.parseLong(line[1]);
		
		long fA ;
		long fB ;
		long result ;
		
		if(A>4) {
			if((A-1)%4==3) {
				fA = 0;
			}else if((A-1)%4==0) {
				fA = A-1;
			}else if((A-1)%4==1) {
				fA = 1;
			}else {
				fA = (A-1)^1;
			}
		}else {
			if ((A-1) == 0) {
				fA = 0;
			}else if((A-1) == 1){
				fA = 1;
			}else if((A-1) == 2){
				fA = 3;
			}else {
				fA = 0;
			}
		}
		
		if(B>=4) {
			if(B%4==3) {
				fB = 0;
			}else if(B%4==0) {
				fB = B;
			}else if(B%4==1) {
				fB = 1;
			}else {
				fB = B^1;
			}
		}else {
			if (B == 0) {
				fB = 0;
			}else if(B == 1){
				fB = 1;
			}else if(B == 2){
				fB = 3;
			}else {
				fB = 0;
			}
		}
		
		System.out.println(fA^fB);
	}

}