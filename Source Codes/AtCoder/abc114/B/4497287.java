import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
//		int potential = 0;
		int abs = Integer.MAX_VALUE;
		for(int i = 0; i < s.length() - 2; i++){
			int num = Integer.parseInt(s.substring(i, i + 3));
//			System.out.println(num);
			if(Math.abs(num-753) < abs){
				abs = Math.abs(num-753);
			}
		}
		System.out.println(abs);
		
	}


}