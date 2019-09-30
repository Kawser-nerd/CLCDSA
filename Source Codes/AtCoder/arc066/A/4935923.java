import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] nums = new long[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        if(n%2==0){
            for(int i=0;i<n;i+=2){
                if(nums[i]!=nums[i+1]||nums[i]!=2*(i/2)+1){
                    System.out.println(0);
                    return;
                }
            }
        }else{
            if(nums[0]!=0){
                System.out.println(0);
                return;
            }
            for(int i=1;i<n;i+=2){
                if(nums[i]!=nums[i+1]||nums[i]!=2*(i/2+1)){
                    System.out.println(0);
                    return;
                }
            }
        }
        long output=1;
        for(int i=0;i<n/2;i++){
            output*=2;
            output%=1000000007;
        }
        System.out.println(output);
    }

}