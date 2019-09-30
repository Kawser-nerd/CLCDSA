import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		String b = sc.next();

		String answer = "";

		switch(b){
			case "A":
				answer = "T";
				break;
			case "T":
				answer = "A";
				break;
			case "C":
				answer = "G";
				break;
			case "G":
				answer = "C";
				break;
			default:
				break;
		}

        System.out.println(answer);
    }
}