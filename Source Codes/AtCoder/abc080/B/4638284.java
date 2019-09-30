import java.util.*;
public class Main {

	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int b =N;
	int count =0;
	for(int i=0;i<8;i++) {
		count+=b%10;
		b=b/10;
	}
	if(N%count==0){
		System.out.println("Yes");
	}
	else{
		System.out.println("No");
	}
	}
	}