import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt(),b=sc.nextInt();
        if(a>b){
            System.out.println(a);
        }else{
            System.out.println(b);
        }

    }


    static String adjustValue(int value) {
        if (10 > value) {
            return "0" + value;
        } else {
            return value + "";
        }
    }
}