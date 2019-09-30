import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input=sc.nextInt();
        if(input<60){
            System.out.println("Bad");
        }else if(input<90){
            System.out.println("Good");
        }else if(input<100){
            System.out.println("Great");
        }else{
            System.out.println("Perfect");
        }
    }
}