import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static int f(int a) {
		if(a%2 == 0) {
			return a/2;
		}else {
			return 3*a+1;
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt();
		int index;
		sc.close();
		ArrayList<Integer> data  =new ArrayList<Integer>();
		while(true) {
			index = data.indexOf(s);
			data.add(s);
			if(index == -1) {
				s = f(s);
			}else {
				break;
			}
		}
		System.out.println(data.size());
	}
}