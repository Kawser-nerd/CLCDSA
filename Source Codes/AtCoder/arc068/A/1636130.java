import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
	Scanner in = new Scanner(System.in);

	long x = in.nextLong();
	long ans = 0;

	ans = (x / 11) * 2;

	if(x % 11 == 0){

	}
	else if(x % 11 < 7){
		ans = ans + 1;
	}else{
		ans = ans + 2;
	}

	System.out.print(ans);

	}

}