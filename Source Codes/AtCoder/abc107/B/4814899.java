import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int h, w;
		h = sc.nextInt();
		w = sc.nextInt();


		String st[] = new String[h + 1];

		char c[][] = new char[h + 1][w + 1];
boolean tate[]=new boolean[h+1];
boolean yoko[]=new boolean[w+1];
Arrays.fill(tate,false);
Arrays.fill(yoko,false);
		for (int i = 1; i <= h; i++) {
			st[i] = sc.next();
			for (int j = 1; j <= w; j++) {
				c[i][j] = st[i].charAt(j-1);
if(c[i][j]=='#'){
	tate[i]=true;
	yoko[j]=true;
}
			}
		}


		for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){

			if(tate[i]&&yoko[j])
			System.out.print(c[i][j]);
		}
		System.out.println();}
	}}