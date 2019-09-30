import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        int[] output=new int[n];
        output[1]=Math.abs(nums[1]-nums[0]);
        for(int i=2;i<n;i++){
            output[i]=Math.min(output[i-1]+Math.abs(nums[i]-nums[i-1]),output[i-2]+Math.abs(nums[i]-nums[i-2]));
        }
        System.out.println(output[n-1]);
    }
}