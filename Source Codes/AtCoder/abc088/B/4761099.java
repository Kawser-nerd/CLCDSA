import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try(Scanner scan = new Scanner(System.in)){
			int N = Integer.parseInt(scan.next());//??????
			List<Integer> list = new ArrayList<Integer>();//?????????
			for(int i=0; i<N; i++) {//???????????
				list.add(Integer.parseInt(scan.next()));
			}
			int turn = 1; // 1:Alice , -1:Bob
			List<Integer> aliceCard = new ArrayList<Integer>();//Alice's Card
			List<Integer> bobCard = new ArrayList<Integer>();// Bob's Card
			
			while(list.size() > 0) {
				int currentMax = getMax(list);
				if(turn == 1) {
					aliceCard.add(currentMax);
				}else{
					bobCard.add(currentMax);
				}
              	turn = turn * -1;
				deleteMax(list, currentMax);
			}
			int aliceSum = getSum(aliceCard);
			int bobSum = getSum(bobCard);
			System.out.println(aliceSum - bobSum);
			
			
		}
	}
	public static int getMax(List<Integer> list) {
		int max = 0;
		for(int num: list) {
			if(num > max) {
				max = num;
			}
		}
		return max;
	}
	 public static void deleteMax(List<Integer> list, int max) {
		 Iterator<Integer> ite = list.iterator();
		 while(ite.hasNext()) {
			 int elm = ite.next();
			 if(elm == max) {
				 ite.remove();
               	 break;
			 }
		 }
	 }
	 public static int getSum(List<Integer> list) {
		 int sum = 0;
		 for(int elm: list) {
			 sum = sum + elm;
		 }
		 return sum;
	 }

}