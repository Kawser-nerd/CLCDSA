import java.util.Scanner;
class Main{
    public static void main(String arg[]){
        Scanner scn= new Scanner(System.in);
        int[] cookie=new int[3];
        for(int i=0;i<3;i++){
            cookie[i]=scn.nextInt();
        }
        if(cookie[0]+cookie[1]>=cookie[2]-1){
            System.out.println(cookie[1]+cookie[2]);
        }else{
            System.out.println(cookie[1]+cookie[1]+cookie[0]+1);
        }
    }
}