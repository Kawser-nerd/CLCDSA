import java.io.*;
import java.util.*;

public class killer {
	 public static Map<String, Integer> priority;
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("killer.in"));
		PrintWriter out = new PrintWriter(new FileWriter("killer.out"));
		int numCases = Integer.parseInt(in.readLine());
		for (int cas = 1; cas<=numCases; cas++){
			out.print("Case #"+cas+":");
			priority = new HashMap<String, Integer>();
			StringTokenizer st = new StringTokenizer(in.readLine());
			int numWords = Integer.parseInt(st.nextToken());
			int numLists = Integer.parseInt(st.nextToken());
			
			ArrayList<String>[] words = new ArrayList[11]; //words[i] is all words w/ length i
			String[] list = new String[numLists];
			for (int i=0; i<words.length; i++)
				words[i] = new ArrayList<String>();
			for (int i=0; i<numWords; i++){
				String toPut = in.readLine();
				priority.put(toPut, i);
				words[toPut.length()].add(toPut);
			}
			for (int i=0; i<numLists; i++)
				list[i] = in.readLine();
			
			for (int i=0; i<numLists; i++){
				String minWord = "";
				int minScore = 1;
				for (int j=0; j<words.length; j++){
					if (words[j].size() == 0) continue;
					String[] helper = new String[1];
					int min = getMin(words[j], helper, list[i], 0, 0);
					if (min < minScore || min==minScore && priority.get(helper[0])<priority.get(minWord)){
						minScore = min;
						minWord = helper[0];
					}
				}
				out.print(" "+minWord);
			}
			out.println();
		}
		out.close();
	}
	
	public static int getMin(ArrayList<String> poss, String[] helper, String guesses, int ind, int numGuess){
		if (poss.isEmpty())
			return 0;
		if (poss.size() == 1 || numGuess == poss.get(0).length()){
			helper[0] = poss.get(0);
			return 0;
		}
		if (!willGuess(poss, guesses.charAt(ind)))
			return getMin(poss, helper, guesses, ind+1, numGuess);
		ArrayList<String>[] enumer = new ArrayList[(1<<poss.get(0).length())];
		for (int i=0; i<enumer.length; i++)
			enumer[i] = new ArrayList<String>();
		for (String word:poss)
			enumer[getEnc(word, guesses.charAt(ind))].add(word);
		
		int minScore = 1;
		for (int i=0; i<enumer.length; i++)
			if (enumer[i].size()!=0){
				String[] help = new String[1];
				int maybeMin = getMin (enumer[i], help, guesses, ind+1, numGuess+Integer.bitCount(i));
				if (i==0) maybeMin--;
				if (maybeMin<minScore || maybeMin==minScore && priority.get(help[0])<priority.get(helper[0])){
					minScore = maybeMin;
					helper[0]=help[0];
				}
			}
		return minScore;
	}
	
	public static int getEnc(String word, char ch){
		int toRet = 0;
		for (int i=0; i<word.length(); i++){
			toRet*=2;
			if (word.charAt(i)==ch) toRet++;
		}
		return toRet;
	}
	
	public static boolean willGuess(ArrayList<String> poss, char ch){
		for (String word:poss)
			if (word.indexOf(ch) != -1)
				return true;
		return false;
	}
}
