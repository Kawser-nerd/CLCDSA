import java.util.*;
public class Main {

	public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int sum = 0;
	for(int i=1;i<=N;i++){
		int ii = i;
		int iii = 0;
		int sum2 =0;
	for(int j=0;j<5;j++){
		iii = ii % 10;
		sum2+=iii;
		ii = ii / 10;
	}
	if(sum2>=A&&sum2<=B){
		sum+=i;
	}
	}
	System.out.println(sum);
	}
	}