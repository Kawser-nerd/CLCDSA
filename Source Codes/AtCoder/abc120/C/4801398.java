import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int result = 0;
		int one =  0;

		for(int i = 0 ; i < S.length() ; i++){
			result = S.indexOf("1", i);
			if(result != -1){
				one +=1;
				i = result;
			}
		}

		int zero = S.length() - one;
		if(one >= zero){
			System.out.println(2 * zero);
		}else{
			System.out.println(2 * one);
		}

	}

}