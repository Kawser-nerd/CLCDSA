import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n==1)System.out.println("Hello World");
        if(n==2) {
        	System.out.println(sc.nextInt()+sc.nextInt());
        }
    }
}