import java.io.*;

public class Main {
    private static int[] goal;
    private static int inputNum = 0;
    private static int[] bamboo;
    private static int[] bPattern;


    private static void increaseBambooPattern(int figure){
        if(figure >= bPattern.length) {

        }else  if(bPattern[figure] >= 3){
            bPattern[figure] = 0;
            increaseBambooPattern(figure+1);
        }else{
            bPattern[figure] += 1;
        }
    }

    private static int calcUsedMP(int[] lengthSum){
        int answer = 0;
        for(int i=1; i<4; i++) {
            answer += Math.abs(goal[i-1] - lengthSum[i]);
        }
        return answer;
    }

    private static int calcAnswer(){
        int[] lengthSum = new int[4];
        int[] mergeNum = new int[4];
        for(int i=0; i<bamboo.length; i++){
            lengthSum[bPattern[i]] += bamboo[i];
            mergeNum[bPattern[i]] ++;
        }

        int mergeMP = 0;
        for(int i=1; i<4; i++){
            if (mergeNum[i] == 0) {
                 return Integer.MAX_VALUE;
            } else if (mergeNum[i] > 1) {
                mergeMP += 10 * (mergeNum[i] - 1);
            }
        }
        return mergeMP + calcUsedMP(lengthSum);
    }

    private static int solveBambooPattern(){
        int answer = Integer.MAX_VALUE;
        bPattern = new int[bamboo.length];
        int loopMax = (int)Math.pow(4, bamboo.length);
        for(int i=0; i<loopMax; i++){
            answer = Math.min(answer, calcAnswer());
            increaseBambooPattern(0);
        }

        return answer;

    }

    private static int solver() {

        return solveBambooPattern();

    }


    public static void main(String[] args) {

        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);

        goal = new int[3];
        try {
            String[] inputArray = br.readLine().split(" ");
            inputNum = Integer.parseInt(inputArray[0]);
            goal[0] = Integer.parseInt(inputArray[1]);
            goal[1] = Integer.parseInt(inputArray[2]);
            goal[2] = Integer.parseInt(inputArray[3]);
        } catch (Exception e) {
            e.printStackTrace();
        }

        bamboo = new int[inputNum];
        for (int i = 0; i < inputNum; i++) {
            try {
                bamboo[i] = Integer.parseInt(br.readLine());
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println(solver());

    }
}