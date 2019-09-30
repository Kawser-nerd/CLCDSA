import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int key = N;
		int []hairetu = new int[10];
		for(int i=0;i<10;i++){
			hairetu[i] = N%10;
			N = N /10;
		}
		int sum =0;
		for(int i=0;i<10;i++){
			sum = sum + hairetu[i];
		}
		if(key % sum==0){
			System.out.println("Yes");
		}
		else{
			System.out.println("No");
		}
	}
}