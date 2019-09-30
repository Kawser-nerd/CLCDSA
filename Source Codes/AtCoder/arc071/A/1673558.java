import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public final class Main {
	public static void main(String [] args){
		Scanner s = new Scanner(System.in);
		int arraySize = Integer.parseInt(s.nextLine().trim());
		ArrayList<String> words = new ArrayList();
		for (int i = 0; i < arraySize; i++){
			words.add(s.nextLine().trim());
		}
		ArrayList<ArrayList<Character>> keeper = new ArrayList();
		for (int i = 0; i < arraySize; i++){
			ArrayList<Character> temp = new ArrayList();
			char[] tempArr = words.get(i).toCharArray();
			for (int x = 0; x < tempArr.length; x++){
				temp.add(tempArr[x]);
			}
			keeper.add(temp);
		}
		ArrayList<Character> resultWords = new ArrayList();
		for (char c : keeper.get(0)){
			boolean shouldAdd = true;
			for (int index = 1; index < keeper.size(); index++){
				ArrayList<Character> arr = keeper.get(index);
				if (arr.contains(c)){
					arr.remove((Object)c);
				} else {
					shouldAdd = false;
				}
			}
			if (shouldAdd){
				resultWords.add(c);
			}
		}
		String result = "";
		while (!resultWords.isEmpty()){
			char c = findLeast(resultWords);
			result += c;
			resultWords.remove((Object)c);
		}
		System.out.println(result);
	}
	
	public static char findLeast(ArrayList<Character> chars){
		char result = 'z';
		for (char c : chars){
			if (c < result){
				result = c;
			}
		}
		return result;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.