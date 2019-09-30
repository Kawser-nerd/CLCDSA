import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		if(b%a == 0){
			System.out.print(a+b);
		}else{
			System.out.print(b-a);
		}
	}
}