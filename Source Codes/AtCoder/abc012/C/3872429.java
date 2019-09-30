import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int sum = sc.nextInt();
		sum =2025-sum;
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++){
				if(i*j==sum){
					System.out.println(i+" x " +j);
				}
			}
		}
	}
}