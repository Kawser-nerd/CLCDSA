import java.util.*;
public class Main {
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int x = 0;
		int y = 0;
		int x1 = 0;
		int y1 = 0;
		int N = sc.nextInt();
		int[] t = {0,0};
		int a = 0;
		Boolean hantei = null;
		for(int i=0;i<N;i++){
			t[0]  = t[1];
			t[1] = sc.nextInt();
			x1 = sc.nextInt();
			y1 = sc.nextInt();
			a = ((t[1]-t[0])-(Math.abs(x1-x)+Math.abs(y1-y)));
			if(a>=0 && a%2==0){
				hantei = true;
			}else{
				hantei = false;
				break;
			}
			x = x1;
			y = y1;
		}
		if(hantei){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}