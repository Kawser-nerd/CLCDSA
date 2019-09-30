import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		String S = sc.next();
		
		String s = S.replace("/", "");
		int date = Integer.parseInt(s);

		String answer = "";

		if(date <= 20190430){
			answer = "Heisei";
		}else{
			answer = "TBD";
		}
		
        System.out.println(answer);
    }
}