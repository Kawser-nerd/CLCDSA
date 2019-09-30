import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String str=scan.next();
	char a[]=new char[5];
	a[0]=str.charAt(0);
	a[1]=str.charAt(1);
	a[2]=str.charAt(2);
	a[3]=str.charAt(3);
	a[4]=str.charAt(4);
	int n = scan.nextInt();
	switch(n) {
	case 1:System.out.println(a[0]+""+a[0]);break;
	case 2:System.out.println(a[0]+""+a[1]);break;
	case 3:System.out.println(a[0]+""+a[2]);break;
	case 4:System.out.println(a[0]+""+a[3]);break;
	case 5:System.out.println(a[0]+""+a[4]);break;
	case 6:System.out.println(a[1]+""+a[0]);break;
	case 7:System.out.println(a[1]+""+a[1]);break;
	case 8:System.out.println(a[1]+""+a[2]);break;
	case 9:System.out.println(a[1]+""+a[3]);break;
	case 10:System.out.println(a[1]+""+a[4]);break;
	case 11:System.out.println(a[2]+""+a[0]);break;
	case 12:System.out.println(a[2]+""+a[1]);break;
	case 13:System.out.println(a[2]+""+a[2]);break;
	case 14:System.out.println(a[2]+""+a[3]);break;
	case 15:System.out.println(a[2]+""+a[4]);break;
	case 16:System.out.println(a[3]+""+a[0]);break;
	case 17:System.out.println(a[3]+""+a[1]);break;
	case 18:System.out.println(a[3]+""+a[2]);break;
	case 19:System.out.println(a[3]+""+a[3]);break;
	case 20:System.out.println(a[3]+""+a[4]);break;
	case 21:System.out.println(a[4]+""+a[0]);break;
	case 22:System.out.println(a[4]+""+a[1]);break;
	case 23:System.out.println(a[4]+""+a[2]);break;
	case 24:System.out.println(a[4]+""+a[3]);break;
	case 25:System.out.println(a[4]+""+a[4]);break;
	}
	}
}