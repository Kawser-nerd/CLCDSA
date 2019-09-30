import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// ?????
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		int X = sc.nextInt();

		int count=0;

		for(int x=0;x<=A&&x*500<=X;x++){
			for(int y=0;y<=B&&(x*500+y*100)<=X;y++){
				if(X-(x*500+y*100+C*50)<=0){
					count++;
				}
			}
		}

		// ??
		System.out.println(count);
	}
}