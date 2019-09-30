import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
String str[]=new String[a];
int b[]=new int[a];
String ans="Niontendo";
int sum=0;
for(int i=0;i!=a;i++) {
	str[i]=scan.next();
	b[i]=scan.nextInt();
sum+=b[i];
}
for(int i=0;i!=a;i++) {
if(b[i]>sum/2) {
	ans=str[i];
}
}
if(ans.equals("Niontendo")) {
	System.out.println("atcoder");
}
else {
	System.out.println(ans);
}
	}
}