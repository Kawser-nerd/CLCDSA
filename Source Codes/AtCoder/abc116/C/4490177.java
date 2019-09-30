import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		List<Integer> heights = new ArrayList<Integer>();
		for(int i = 0; i < N; i++) {
			heights.add(sc.nextInt());
		}
		sc.close();
		int number = getHeight(heights);
		System.out.println(number);
	}
	
	static int getHeight(List<Integer> heights) {
		if(heights.size() == 0) return 0;
		if(heights.size() == 1) return heights.get(0);
		int number = findSmallest(heights);
		List<Integer> updatedList = updateHeights(heights, number);
		List<List<Integer>> partitions = divide(updatedList);
		for(List<Integer> list: partitions) {
			number += getHeight(list);
		}
		return number;
		
	}
	
	static int findSmallest(List<Integer> heights) {
		int temp = heights.get(0);
		for(int x : heights) {
			if(temp > x) {
				temp = x;
			}
		}
		return temp;
	}
	
	static List<Integer> updateHeights(List<Integer>heights, int number) {
		List<Integer> list = new ArrayList<Integer>();
		for(int x: heights) {
			list.add(x - number);;
		}
		return list;
	}
	
	static List<List<Integer>> divide(List<Integer> heights){
		List<List<Integer>> partitions = new ArrayList<List<Integer>>();
		List<Integer> list = null;
		for(int i = 0; i < heights.size(); i++) {
			if(i == 0 ||  heights.get(i) == 0) {
				if(list != null) {
					partitions.add(list);
				}
				list = new ArrayList<Integer>();
			}
			if(heights.get(i) != 0) {
				list.add(heights.get(i));
				if(i == heights.size() - 1) {
					partitions.add(list);
				}
			}
		}
		return partitions;
	}
		
}