import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        if(n < 60){
            System.out.println("Bad");
            
        }else if(n < 90){
            System.out.println("Good");
        }else if(n < 100){
            System.out.println("Great");
        }else{
            System.out.println("Perfect");
        }
    }
}