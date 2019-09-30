import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String str[] = sc.next().split("");

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();

		String answer = "";
		for(int i =0;i < str.length;i++){
			if(a == i || b == i || c == i || d == i){
				answer += "\"";
			}
			answer += str[i];
		}

		if(d == str.length)answer += "\"";

		System.out.println(answer);
	}
}