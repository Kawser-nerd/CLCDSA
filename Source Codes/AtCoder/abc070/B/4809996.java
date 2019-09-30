import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int D = sc.nextInt();	
		sc.close();
		
		System.out.println(subAbs(A, B, C, D));
	}
	
	public static int subAbs(int A, int B, int C, int D){
		int sub = Math.min(B, D) - Math.max(A, C);
		if( sub > 0) {
			return sub;
		}else {
			return 0;
		}
	}
}