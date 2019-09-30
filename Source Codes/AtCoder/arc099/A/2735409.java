import java.util.*;
public class Main{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int num0 = sc.nextInt();
        int num1 = sc.nextInt();
        int i;
        int[] list = new int[num0];
        int min = 0;

        for(i = 0;i < num0;i++){
            list[i] = sc.nextInt();
            if(list[i] == 1){
                min = i;
            }
        }

        int ans = (num0 - 1) / (num1- 1) + 1;
        if((num0 - 1) % (num1 - 1) == 0){
            ans -= 1;
        }
        System.out.println(ans);
    }
}