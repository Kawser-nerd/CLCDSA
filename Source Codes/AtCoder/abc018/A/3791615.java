import java.util.Scanner;
public class Main {
public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int b=scan.nextInt();
int c=scan.nextInt();
if(a>b&&b>c&&a>c) {System.out.println(1+"\n"+2+"\n"+3);}
if(a>b&&b<c&&a>c) {System.out.println(1+"\n"+3+"\n"+2);}
if(a<b&&b>c&&a>c) {System.out.println(2+"\n"+1+"\n"+3);}
if(a<b&&b>c&&a<c) {System.out.println(3+"\n"+1+"\n"+2);}
if(a<b&&b<c&&a<c) {System.out.println(3+"\n"+2+"\n"+1);}
if(a>b&&b<c&&a<c) {System.out.println(2+"\n"+3+"\n"+1);}

}
}