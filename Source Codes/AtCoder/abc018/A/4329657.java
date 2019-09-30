import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums=new int[3];
        for(int i=0;i<3;i++){
            nums[i]=sc.nextInt();
        }
        int output;
        for(int i=0;i<3;i++){
            output=1;
            for(int j=0;j<3;j++){
                if(nums[i]<nums[j]){
                    output++;
                }
            }
            System.out.println(output);
        }
    }

}