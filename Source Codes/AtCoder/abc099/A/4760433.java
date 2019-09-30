import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String name = null;
		if(N <= 999){
			name = "ABC";
		}else{
			name = "ABD";
		}
		System.out.println(name);
	}
}