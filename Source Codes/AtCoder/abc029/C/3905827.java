import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		judge(a,"a","");
		judge(a,"b","");
		judge(a,"c","");
	}
	public static void judge(int a, String b,String c){
		
		c=c+b;
		if(a==1){
			System.out.println(c);
			return;
		}
		judge(a-1,"a",c);
		judge(a-1,"b",c);
		judge(a-1,"c",c);
	}
}