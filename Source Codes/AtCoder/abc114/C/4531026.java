import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args){	
		Scanner sc = new Scanner(System.in);
		Map<Integer, Set<Integer>> nums = new HashMap<Integer, Set<Integer>>();
		Set<Integer> three = new HashSet<Integer>();
		three.add(573);
		three.add(357);
		three.add(375);
		three.add(537);
		three.add(735);
		three.add(753);
		nums.put(3, three);
		int comparedNum = sc.nextInt();
		int n = numProducer(nums, comparedNum);
		System.out.println(n);
				
	}
	
	public static int numProducer(Map<Integer, Set<Integer>> nums, int comparedNum){
		if(comparedNum < 100) return 0;
		List<Character> cN = numToCharacter(comparedNum);
		int totalNum = 0;
		if(nums.containsKey(cN.size())){
			Set<Integer> s = nums.get(cN.size());
			for(int i : s){
				if(i <= comparedNum){
					totalNum++;
				}
			}
			int len = cN.size() - 1;
			while(nums.containsKey(len)){
				totalNum += nums.get(len).size();
				len--;
			}	
			return totalNum;
		}else{
			int len = cN.size() - 1;
			while(!nums.containsKey(len)){
				len--;
			}
			
			while(len < cN.size()){
				Set<Integer> s = nums.get(len);
				Set<Integer> total = new HashSet<Integer>();
				int[] generator = new int[]{3,5,7};
				for(int x : generator){
					Set<Integer> integers = smallNumProducer(s, x);
					total.addAll(integers);
				}
				nums.put(++len, total);
			}
			return numProducer(nums, comparedNum);
			
		}
	}
	
	public static Set<Integer> smallNumProducer(Set<Integer> list, int num){
		Set<Integer> nums = new HashSet<Integer>();
		for(int n: list){
			Set<Integer> ns = oneNumProducer(n, num);
			nums.addAll(ns);
		}
		return nums;
	}
	
	public static Set<Integer> oneNumProducer(int n, int num){
		Set<Integer> newNumbers = new HashSet<Integer>();
		List<Character> numbers = numToCharacter(n);
		for(int i = 0; i <= numbers.size(); i++){
			numbers.add(i, (char)(num + '0'));
			newNumbers.add(charToNum(numbers));
			numbers.remove(i);
		}
		return newNumbers;
	}
	
	public static int charToNum(List<Character> list){
		char[] chars = new char[list.size()];
		for(int i = 0; i < list.size(); i++){
			chars[i] = list.get(i);
		}
		String s = new String(chars);
		return Integer.parseInt(s);
	}
	
	public static List<Character> numToCharacter(int n){
		LinkedList<Character> numToChar = new LinkedList<Character>();
		while(n != 0){
			numToChar.addFirst((char)((n % 10) + '0'));
			n = n/10;
		}
		return numToChar;
	}

}