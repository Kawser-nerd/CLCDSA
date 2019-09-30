import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] inputArray = new int[N];
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0; i<N; i++){
            int input = sc.nextInt();
            inputArray[i] = input;
        }

        for(int i=0; i<inputArray.length; i++){
            if(i == 0){
                List<Integer> newList = new ArrayList<>();
                newList.add(inputArray[i]);
                list.add(newList);
            } else {
                for(int j=0; j<list.size(); j++){

                    int last = list.get(j).get(list.get(j).size()-1);
                    if(inputArray[i] <= last){
                        list.get(j).add(inputArray[i]);
                        break;
                    } else {
                        if(j == list.size()-1){
                            List<Integer> newList = new ArrayList<>();
                            newList.add(inputArray[i]);
                            list.add(newList);
                            break;
                        } else {
                            continue;
                        }
                    }
                }
            }
        }

        System.out.println(list.size());
    }

//    void dfs(int from, List<Integer> list, boolean[] reachedNodes){
////        System.out.println(eachCount);
//        int eachCount = 0;
//        for(boolean b: reachedNodes){
//            if(b){
//                eachCount++;
//            }
//        }
//        if(eachCount == N){
//            count++;
//            return;
//        }
////
//        for(int i: list){
//            if(reachedNodes[i]){
//                continue;
//            }
//            reachedNodes[i] = true;
////            System.out.println(String.format("%s %s", from+1, i+1));
//            dfs(i, map.get(i), reachedNodes);
//            reachedNodes[i] = false;
//        }
//    }

//    void dfs(int from, List<Integer> toList, boolean[] eachReachedNode, boolean[][] threwEdge, boolean countedFlug) {
//
//        reachedNode[from] = true;
//        eachReachedNode[from] = true;
//
//        for (int i : toList) {
//            if ((threwEdge[from][i] || threwEdge[i][from])) {
//                continue;
//            } else if(eachReachedNode[i] && !countedFlug){
////                System.out.println(String.format("%s %s", from , i));
//                count++;
//                countedFlug = true;
//                threwEdge[from][i] = true;
//                threwEdge[i][from] = true;
////                return;
//            } else {
//                if(map.get(i) == null){
//                    return;
//                } else {
//                    threwEdge[from][i] = true;
//                    threwEdge[i][from] = true;
//                    dfs(i, map.get(i), eachReachedNode, threwEdge, countedFlug);
//                }
//            }
//        }
//    }
//    void dfs(int from, int to) {
//
//        if (from > 100 || to > 100 || reachedArray[from][to]) {
//            return;
//        }
//
//        reachedArray[from][to] = true;
//
//        if (hasArray[from][to]) {
//            count++;
//        }
//        dfs(to, to + 1);
//        dfs(to + 1, to);
//    }
}