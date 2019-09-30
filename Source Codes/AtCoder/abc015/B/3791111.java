import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
double count=0;
double ans=0;
for(int i=0;i!=a;i++) {
	int bug=scan.nextInt();
	if(bug!=0) {count++;ans+=bug;}
}
ans=Math.ceil(ans/count);
System.out.println((int)ans);
}
}