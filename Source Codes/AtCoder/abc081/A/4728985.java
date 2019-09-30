import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		sc.close();
		String[]S = s.split(""); 
		int count = 0;
		
		for(int i = 0; i < S.length; i++) {
			if(S[i].equals("1")) {
				count++;
			}
		}
		System.out.println(count);
	}
}