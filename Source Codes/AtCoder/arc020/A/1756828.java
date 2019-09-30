import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int a = Math.abs(scanner.nextInt());
        int b = Math.abs(scanner.nextInt());
        if(a < b){
            System.out.println("Ant");
        }
        else if(a == b){
            System.out.println("Draw");
        }
        else{
            System.out.println("Bug");
        }
    }
}