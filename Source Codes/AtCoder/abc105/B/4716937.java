import java.util.*;
public class Main {

	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(N == 4 * i + 7 * j){
				System.out.println("Yes");
				System.exit(0);
			}
		}
	}
	System.out.println("No");

	}

}