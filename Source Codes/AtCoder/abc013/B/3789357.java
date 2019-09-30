import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int b=scan.nextInt();
int ans=100000;
	if(ans>a-b&&a-b>=0) {
	ans=(a-b);
}	if(ans>b-a&&b-a>=0) {
	ans=(b-a);
}
if(ans>(9-a)+(1+b)&&9-a>=0) {
	ans=(9-a)+(1+b);}
if(ans>(9-b)+(1+a)&&9-b>=0) {
	ans=(9-b)+(1+a);}
System.out.println(ans);

}
}