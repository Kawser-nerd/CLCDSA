import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int [][] nums=new int[sc.nextInt()][sc.nextInt()];
        int[] place=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<nums[0].length;j++){
                nums[i][j]=sc.nextInt();
            }
        }
        int tmp=0;
        for(int i=0;i<Math.pow(nums[0].length,nums.length);i++){
            for(int j=0;j<nums.length;j++){
                if(j==0){
                    tmp=nums[0][place[0]];
                }else{
                    tmp=tmp^nums[j][place[j]];
                }
            }
            if(tmp==0){
                System.out.println("Found");
                return;
            }
            place[0]++;
            for(int j=0;j<place.length-1;j++){
                if(place[j]>=nums[0].length){
                    place[j]=0;
                    place[j+1]++;
                }
            }
        }
        System.out.println("Nothing");
        
        
    }

}