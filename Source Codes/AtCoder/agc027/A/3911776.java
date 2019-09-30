import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();
	int x = scan.nextInt();

	int[] a_ = new int[N];
	for(int i = 0; i < N; i++){
	    a_[i] = scan.nextInt();
	}

	Arrays.sort(a_);

	int ans = 0;
	for(int i = 0; i < N; i++){
	    x -= a_[i];
	    if(x < 0){
		break;
	    }else{
		ans++;
	    }
	}

	if(x > 0){
	    ans--;
	}
	System.out.println(ans);
    }
}