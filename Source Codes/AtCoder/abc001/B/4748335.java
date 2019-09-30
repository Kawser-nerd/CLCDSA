import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		 int a = sc.nextInt();

		 double aa = a/1000.0;

		 int ans = 0;

		 	if(aa < 0.1){
		 		ans = 0;
		 	}

		 	else if(aa>=0.1 && aa <= 5){
		 		ans = (int)(aa * 10);
		 	}

		 	else if(aa >= 6 && aa <= 30){
		 		ans = (int)(aa + 50);
		 	}

		 	else if(aa >= 35 && aa <= 70){
		 		ans = (int)((aa-30)/5 + 80);
		 	}
		 	else if(aa > 70){
		 		ans = 89;
		 	}

		 	String bb = String.format("%02d", ans);

		 	System.out.println(bb);

	}
}