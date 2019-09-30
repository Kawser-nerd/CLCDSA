import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int b=scan.nextInt();
String bin = Integer.toBinaryString(b);
long ans=0;
for(int i=0;i!=bin.length()
;i++) {
	int c=scan.nextInt();
	if(bin.charAt(bin.length()-1-i)=='1') {ans+=c;}
	}
System.out.println(+ans);
}
}