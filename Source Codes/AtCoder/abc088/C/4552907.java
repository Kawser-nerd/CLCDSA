import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int c[][]=new int[3][3];
		int z=0,y=0,fin=0,a1=0,a2=0;
		while(z<3){
			while(y<3){
				c[z][y]=stdIn.nextInt();
				y++;
			}y=0;
			z++;
		}z=1;
		a1=c[0][0]-c[0][1];
		a2=c[0][1]-c[0][2];
		while(z<3){
			if(c[z][0]-c[z][1]!=a1){
				fin=1;
				break;
			}
			if(c[z][1]-c[z][2]!=a2){
				fin=1;
				break;
			}
			z++;
		}
		if(fin==1)
			System.out.println("No");
		else
			System.out.println("Yes");
	}

}