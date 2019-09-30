import java.util.*;

public class Main {
    public static void main(String[] args){

        int timeData = 0;
        int[][] times = new int[289][2];

        for (int i=0; i<289; i++){
            times[i][0] = timeData;
            timeData += 5;

            if (i != 0 && (times[i][0]%100) == 55) timeData = (timeData / 100 + 1) * 100;
        }

        // input
        Scanner sc = new Scanner(System.in);
        int inputCount = sc.nextInt();
        for (int i=0; i<inputCount; i++) {
            String[] lainTime = sc.next().split("-");
            int from = Integer.valueOf(lainTime[0]);
            int to =Integer.valueOf(lainTime[1]);

            // ??
            from = from - from % 5;

            for (int j=0; j<289; j++){
                if (times[j][0] >= from && times[j][0] < to) times[j][1] = 1;
            }
        }

        // output
        ArrayList<String> resultList = new ArrayList<>();
        String result = "";
        boolean isContinue = false;

        for (int i=0; i<times.length; i++) {

            if(isContinue) {
                if (times[i][1] == 0) {
                    isContinue = false;
                    String intResult = "0000" + times[i][0];
                    result += "-" + intResult.substring(intResult.length()-4);
                    resultList.add(result);
                    result = "";
                }
            }
            else {
                if (times[i][1] == 1) {
                    isContinue = true;
                    result = "0000" + (times[i][0]);
                    result = result.substring(result.length()-4);
                }
            }

            if (isContinue && i==288) {
                result += "-2400";
                resultList.add(result);
            }
        }

        for (String output : resultList) {
            System.out.println(output);
        }
    }
}