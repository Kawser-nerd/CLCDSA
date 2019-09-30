import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int plot[] = new int[1000];
        for(int i = 0; i < plot.length; i++){
            plot[i] = 0;
        }
        for(int i = 0; i < n; i++){
            String baseTime = sc.next();
            String times[] = baseTime.split("-");
            int startTime = Integer.parseInt(times[0]);
            int endTime = Integer.parseInt(times[1]);
            int start = startTime - (startTime % 5);
            int end = endTime + (5 - (endTime % 5) == 5 ? 0 : 5 - (endTime % 5));
            if(end % 100 > 59){
                end += 100 - 60 + (end % 100 - 60);
            }
            int startIndex = start / 5;
            int endIndex = end / 5;
            for(int j = startIndex; j < endIndex; j++){
                plot[j] = 1;
            }
        }
        boolean startFlag = false;
        for(int i = 0; i < plot.length; i++){
            if(!startFlag){
                if(plot[i] == 1){
                    System.out.print(String.format("%04d", (i * 5)) + "-");
                    startFlag = true;
                }
            }else{
                if(plot[i] == 0){
                    System.out.println(String.format("%04d", (i * 5)));
                    startFlag = false;
                }
            }
        }
    }
}