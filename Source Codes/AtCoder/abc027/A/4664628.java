import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums=new int[3];
        for(int i=0;i<3;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        if(nums[0]!=nums[1]){
            System.out.println(nums[0]);
        }else{
            System.out.println(nums[2]);
        }
    }
}