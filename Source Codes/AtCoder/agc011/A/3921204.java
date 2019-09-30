import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();  //??
	int C = scan.nextInt();  //??
	int K = scan.nextInt();  //????

	int[] T_ = new int[N];
	for(int i = 0; i < N; i++){
	    T_[i] = scan.nextInt();
	}
	Arrays.sort(T_);

	int count = 1;
	int max = T_[0]+K;
	loop: for(int i = 0; i < N;){
	    int index = i;
	    for(int j = index; j < index+C; j++){
		if(j < N && T_[j] <= max){
		    i++;
		}else if(j < N){
		    break;
		}
		else{
		    break loop;
		}
	    }
	    if(i < N){
		max = T_[i]+K;
		count++;
	    }
	}

	System.out.println(count);
    }
}