import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();

	int[] a_ = new int[3*N];
	for(int i = 0; i < 3*N; i++){
	    a_[i] = scan.nextInt();
	}

	Arrays.sort(a_);

	long ans = 0;
	if(N % 2 == 0){
	    for(int i = N; i < 3*N; i++){
		if(i % 2 == 0){
		    ans += a_[i];
		}else{
		}
	    }
	}else{
	    for(int i = N; i < 3*N; i++){
		if(i % 2 != 0){
		    ans += a_[i];
		}else{
		}
	    }
	}
	
	System.out.println(ans);
    }
}