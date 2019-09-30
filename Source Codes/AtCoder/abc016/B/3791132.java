import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int b=scan.nextInt();
int c=scan.nextInt();
if(a+b==c&&a-b==c) {System.out.println("?");}
else if(a+b==c) {System.out.println("+");}
else if(a+b!=c&&a-b!=c) {System.out.println("!");}
else {System.out.println("-");}
}
}