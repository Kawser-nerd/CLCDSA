import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();

int x3,y3,x4,y4;
int xsa,ysa;
xsa=x2-x1;
ysa=y2-y1;
x3=x2-ysa;
y3=y2+xsa;
x4=x3-xsa;
y4=y3-ysa;


System.out.println(x3+" "+y3+" "+x4+" "+y4);

	}}