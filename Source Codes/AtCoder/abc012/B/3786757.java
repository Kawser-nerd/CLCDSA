import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int s=0,m=0,h=0;
s=a;
m=s/60;
s=s-60*m;
h=m/60;
m=m-60*h;
String as=""+s,am=""+m,ah=""+h;
if(s%100<10) {as="0"+s;}
if(m%100<10) {am="0"+m;}
if(h%100<10) {ah="0"+h;}
System.out.println(ah+":"+am+":"+as);
}
}