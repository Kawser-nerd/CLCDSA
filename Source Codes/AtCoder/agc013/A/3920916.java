import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();

	int[] A_ = new int[N];
	for(int i = 0; i < N; i++){
	    A_[i] = scan.nextInt();
	}

	int now = A_[0];
	int count = 1;
	for(int i = 1; i < N;){
	    if(now < A_[i]){
		while(i < N && now <= A_[i]){
		    now = A_[i];
		    i++;
		}
	    }else if(now > A_[i]){
		while(i < N && now >= A_[i]){
		    now = A_[i];
		    i++;
		}
	    }else{
		i++;
		continue;
	    }
	    if(i < N){
		now = A_[i];
		count++;
	    }
	}

	System.out.println(count);
    }
}