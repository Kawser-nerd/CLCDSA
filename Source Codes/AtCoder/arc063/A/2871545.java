import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		char[] S = sc.next().toCharArray();
		int cnt=0;
		for(int i=0;i<S.length-1;i++){
			if(S[i]!=S[i+1]) cnt++;
		}
		System.out.println(cnt);
	}
}