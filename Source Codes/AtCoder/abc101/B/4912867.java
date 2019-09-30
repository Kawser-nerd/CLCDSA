import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();//S(N)
        int lon = num;
        int sum = 0;  //num?????

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        if(lon % sum == 0){
            System.out.println("Yes");
        }else 
            System.out.println("No");
    }
}