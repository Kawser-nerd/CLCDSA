import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		int answer = 0;

		int count = B / A;

		if (count > C){
			answer = C;
		}else{
			answer = count;
		}
		
        System.out.println(answer);
    }
}