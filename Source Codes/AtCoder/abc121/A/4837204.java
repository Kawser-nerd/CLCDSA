import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int H,W,h,w,block,ans;

		H = sc.nextInt();
		W = sc.nextInt();
		h = sc.nextInt();
		w = sc.nextInt();
		
		block = H*W - (W*h+H*w-h*w);
		
		System.out.println(block);
	}
}