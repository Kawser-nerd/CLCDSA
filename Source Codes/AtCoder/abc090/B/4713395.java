import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int count =0;
		for(int i=A;i<=B;i++){
			int a = i / 10000;
			int b = i % 10;
			int c = i / 10 % 10;
			int d = i / 1000 % 10;
			if(a==b&&c==d){
				count++;
			}
		}
		System.out.println(count);
	}
}