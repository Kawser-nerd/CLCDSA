import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] outputs={"Do","Re","Mi","Fa","So","La","Si"};
        String input=sc.next().substring(0,12);
        String colors="WBWBWWBWBWBW";
        for(int i=0;i<7;i++){
            if(input.equals(colors)){
                System.out.println(outputs[i]);
                return;
            }
            do{
                colors=colors.substring(1,12)+colors.substring(0,1);
            }while(colors.charAt(0)=='B');
        }
    }
}