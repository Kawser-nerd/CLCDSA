import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(a%b==0) {
            System.out.println(0);
        }else{
            System.out.println(b-a%b);
        }
    }
}