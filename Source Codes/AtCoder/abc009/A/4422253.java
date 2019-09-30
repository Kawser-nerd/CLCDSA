import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println((n%2 == 0) ? n/2 : (n/2)+1);
    }
}