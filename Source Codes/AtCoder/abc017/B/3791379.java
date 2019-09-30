import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
String a=scan.next();
int ans=0;
for(int i=0;i!=a.length();i++) {
	char b=a.charAt(i);
	if(i==0&&b=='h') {ans=1;break;}
	if(b!='c'&&b!='h'&&b!='o'&&b!='k'&&b!='u') {ans=1;break;}
	if(i<=a.length()-2&&b=='c'&&a.charAt(i+1)!='h') {ans=1;break;}
	if(i>=1&&b=='h'&&a.charAt(i-1)!='c'){ans=1;break;}
	if(i==a.length()-1&&(b=='c'||b=='h')) {ans=1;break;}
}
if(ans==0) {System.out.println("YES");}
else {System.out.println("NO");}
}
}