import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt(), B = scn.nextInt(),C = scn.nextInt(),D = scn.nextInt();
		String ans;
		if(A+B > C+D) {
			ans = "Left";
		}else if(A+B==C+D){
			ans = "Balanced";
		}else {
			ans = "Right";
		}
		System.out.println(ans);
	}

}