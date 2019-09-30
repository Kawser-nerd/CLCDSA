import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);

        //System.out.println("?????????????");
        int a = sc.nextInt();

        //System.out.println("?????????????");
        int b = sc.nextInt();

        //System.out.println("?????????????");
        int c = sc.nextInt();

        //System.out.println("???????????????");
        int k = sc.nextInt();

        //System.out.println("????????????????");
        int s = sc.nextInt();

        //System.out.println("????????????????");
        int t = sc.nextInt();

        int sum = 0;
        if (s + t >= k) {
            sum = sum + (s * (a-c) + t * (b-c) );
           // System.out.println(sum);

        } else {
            sum = sum + (s * a + t * b);
            //System.out.println(sum);

        }

        System.out.println(sum);

    }

}