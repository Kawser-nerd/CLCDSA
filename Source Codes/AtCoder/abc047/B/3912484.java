import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int W = scan.nextInt();
	int H = scan.nextInt();
	int N = scan.nextInt();

	int[] x_ = new int[N];
	int[] y_ = new int[N];
	int[] a_ = new int[N];

	for(int i = 0; i < N; i++){
	    x_[i] = scan.nextInt();
	    y_[i] = scan.nextInt();
	    a_[i] = scan.nextInt();
	}

	int x_l = 0;
	int x_r = W;
	int y_d = 0;
	int y_u = H;

	for(int i = 0; i < N; i++){
	    //x < xi
	    if(a_[i] == 1){
		if(x_[i] > x_l)
		    x_l = x_[i];
	    //x > xi
	    }else if(a_[i] == 2){
		if(x_[i] < x_r)
		    x_r = x_[i];
	    //y < yi
	    }else if(a_[i] == 3){
		if(y_[i] > y_d)
		    y_d = y_[i];
	    //y > yi
	    }else if(a_[i] == 4){
		if(y_[i] < y_u)
		    y_u = y_[i];
	    }
	}

	if(y_d >= y_u || x_l >= x_r){
	    System.out.println(0);
	}else{
	    System.out.println((x_r-x_l)*(y_u-y_d));
	}
    }
}