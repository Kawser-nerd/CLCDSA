import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums=new int[3];
        for(int i=0;i<3;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        if(nums[0]==5&&nums[1]==5&&nums[2]==7){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
    
 
}