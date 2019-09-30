import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] nums=new int[sc.nextInt()];
        for(int i=0;i<nums.length;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        int tmp=0;
        int output=0;
        for(int a:nums){
            if(tmp==a){
                output++;
            }
            tmp=a;
        }
        System.out.println(output);
        
    }
        

    

}