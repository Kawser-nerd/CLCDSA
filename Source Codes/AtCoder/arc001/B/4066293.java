import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int start = sc.nextInt();
        int goal = sc.nextInt();
        int count = 0;

        while(start != goal){
            if(start < goal){
                count++;
                int testA = start+10;
                int testB = start+5;
                int testC = start+1;
                List<Integer> list = Arrays.asList(testA, testB, testC);
                start = list.stream().min(Comparator.comparing((Integer x) -> Math.abs(x - goal))).get();
            }
            else if(start > goal){
                count++;
                int testA = start-10;
                int testB = start-5;
                int testC = start-1;
                List<Integer> list = Arrays.asList(testA, testB, testC);
                start = list.stream().min(Comparator.comparing((Integer x) -> Math.abs(x - goal))).get();
            }
        }
        System.out.println(count);
        
    }
}