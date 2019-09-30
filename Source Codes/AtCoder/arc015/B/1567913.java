import java.util.*;

public class Main {
    private static int n;
    private static ArrayList<Double> maxT = new ArrayList<>();
    private static ArrayList<Double> minT = new ArrayList<>();
    private static int count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();

        for (int i=0;i<n;i++){
            maxT.add(scan.nextDouble());
            minT.add(scan.nextDouble());
        }
    }

    public static void main(String args[]) {
        //??
        input();

        for (int i=0;i<maxT.size();i++){
            double max = maxT.get(i);
            if(max >= 35) count1++;
            else if(max >= 30) count2++;
            else if(max >= 25) count3++;
            else if(max < 0) count6++;

            double min = minT.get(i);
            if(min >= 25) count4++;
            else if(min < 0 && max >= 0) count5++;
        }
        
        System.out.println(count1 + " " + count2 + " " + count3 + " " + count4 + " " + count5 + " " + count6);
    }
}