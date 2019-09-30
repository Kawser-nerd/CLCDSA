import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int high = 0;
		for(int n=1;n<b-a;n++){
			high += n;
		}
		System.out.println(high-a);

	}
}