import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] nums=new int[n];
        int people=0;
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
            people+=nums[i];
        }
        if(people%n!=0){
            System.out.println(-1);
            return;
        }
        people/=n;
        int sum=0;
        int output=n;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==people*(i+1)){
                output--;
            }
        }
        System.out.println(output);
    }
}