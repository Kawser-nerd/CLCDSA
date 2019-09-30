import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int[] nums=new int[sc.nextInt()+2];
        nums[0]=a;
        for(int i=0;i<nums.length-2;i++){
            nums[i+1]=sc.nextInt();
        }
        nums[nums.length-1]=b;
        Arrays.sort(nums);
        int tmp=0;
        for(int c:nums){
            if(tmp==c){
                System.out.println("NO");
                return;
            }
            tmp=c;
        }
        System.out.println("YES");
    }
        

    

}