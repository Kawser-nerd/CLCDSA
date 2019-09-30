import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();  //?????

	long[] A_ = new long[N];  //???????????
	int odd = 0;
	int even = 0;
	for(int i = 0; i < N; i++){
	    A_[i] = scan.nextLong();
	    if(A_[i] % 2 == 0)
		even++;
	    else
		odd++;
	}

	int flag = 1;
	while(odd+even > 1){
	    while(odd > 1){
		odd -= 2;
		even++;
	    }while(even > 1){
		even--;
	    }
	    if(odd == 1 && even == 1){
		flag = -1;
		break;
	    }
	}

	if(flag == 1){
	    System.out.println("YES");
	}else{
	    System.out.println("NO");
	}
    }
}