import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		double a=scan.nextInt(),b=scan.nextInt();
		if(a>12) {
			a=a-12;
		}
		double min=a*30+b*0.5;
		if(min>360) {
			min=min-360;
		}
		double hou=b*6;
		double ans=0;
		if(min<=hou) {
			ans=hou-min;
		}
		else {
			ans=min-hou;
		}
		if(ans>180) {
			ans=360-ans;
		}
		System.out.println(ans);
	}
}