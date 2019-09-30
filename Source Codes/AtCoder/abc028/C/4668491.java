import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums=new int[5];
        int[] sums=new int[10];
        for(int i=0;i<5;i++){
            nums[i]=sc.nextInt();
        }
        int length=0;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                for(int k=j+1;k<5;k++){
                    sums[length]=nums[i]+nums[j]+nums[k];
                    length++;
                }
            }
        }
        Arrays.sort(sums);
        int count=0;
        int tmp=0;
        for(int i=10;i>0;i--){
            count++;
            if(tmp==sums[i-1])count--;
            if(count==3){
                System.out.println(sums[i-1]);
                return;
            }
        }
    }
}