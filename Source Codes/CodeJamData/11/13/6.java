package jam2011;
import java.io.*;
import java.util.*;

// Marian G Olteanu
// round 1A
public class AC
{
	public static final int C = 0;
	public static final int S = 1;
	public static final int T = 2;
	public static int bestScore;
	public static int maxPossibleScore;
	public static long updateTime;
	
	public static void main(String[] args)
	throws Exception
	{
		BufferedReader inputFile = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
		int cases = Integer.parseInt(inputFile.readLine());
		
		long time = System.currentTimeMillis();
		PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
		for (int i = 1; i <= cases; i++)
		{
			//String lineT[] = tokenize(inputFile.readLine());
			int n = Integer.parseInt(inputFile.readLine());
			int[] cardsInHand = new int[n];
			for (int j = 0; j < n; j++)
				cardsInHand[j] = readCard(inputFile.readLine());
			
			int m = Integer.parseInt(inputFile.readLine());
			int[] cardsInDeck = new int[m];
			for (int j = 0; j < m; j++)
				cardsInDeck[j] = readCard(inputFile.readLine());
			
			maxPossibleScore = 0;
			for (int c : cardsInHand)
				maxPossibleScore += getS(c);
			for (int c : cardsInDeck)
				maxPossibleScore += getS(c);
			bestScore = -1;
			
			//System.out.println("best score: " + maxPossibleScore);
			
			Map<Integer , int[]> countInHand = new TreeMap<Integer, int[]>();
			for (int j = 0; j < cardsInHand.length; j++)
				countInHand.put(cardsInHand[j] , new int[]{0});
			for (int j = 0; j < cardsInDeck.length; j++)
				countInHand.put(cardsInDeck[j] , new int[]{0});
			
			for (int j = 0; j < cardsInHand.length; j++)
				countInHand.get(cardsInHand[j])[0]++;
			
			//if (i == 23)
			{
				//System.out.println("#" + i + "  " + n + " " + m);
				runAlgorithm(1 , countInHand, cardsInDeck , 0 , 0);
			}
			
			outFile.println("Case #" + i + ": " + bestScore);
			//System.err.println("Case #" + i + " - " + (System.currentTimeMillis() - time)/1000 + "s");
			
		}
		
		
		outFile.close();
		inputFile.close();
	}
	private static int getC(int card)
	{
		return 99-card / 10000;
	}
	private static int getS(int card)
	{
		return 99-(card % 10000) / 100;
	}
	private static int getT(int card)
	{
		return 99-card % 100;
	}
	
	private static void runAlgorithm(int turnsLeft, Map<Integer , int[]> countInHand, int[] cardsInDeck , int idxInDeck , int accumulatedScore)
	{
		// optimum reached
		if (bestScore == maxPossibleScore)
			return;
		
		// update best score
		if (bestScore < accumulatedScore)
		{
			updateTime = System.currentTimeMillis();
			bestScore = accumulatedScore;
		}
//			System.out.println(accumulatedScore);
		//bestScore = Math.max(bestScore , accumulatedScore);
		if (turnsLeft == 0)
			return;
		
		// play a turn
		turnsLeft--;
		
		Set<Integer> usedCT = new HashSet<Integer>();
		
		for (Integer card : countInHand.keySet())
			if (countInHand.get(card)[0] > 0)
			{
				//System.out.println(card);
				int cardT = getT(card);
				int cardC = getC(card);
				int signiature = cardT*100 + cardC;
				if (usedCT.contains(signiature))
				{
					//System.out.println("  skip  " + bestScore);
					continue;
				}
				//System.out.println(card);
				usedCT.add(signiature);
				
				// play it
				countInHand.get(card)[0]--;
				//System.out.println("Turns left: " + (turnsLeft) + " score: " + accumulatedScore + " drawn: " + idxInDeck + "    " + getC(card) + " " + getS(card) + " " + getT(card);
				int newScore = accumulatedScore + getS(card);
				int newTurnsLeft = turnsLeft + cardT;
				int drawFromDeck = cardC;
				
				for (int i = idxInDeck; i < idxInDeck + drawFromDeck && i < cardsInDeck.length; i++)
					countInHand.get(cardsInDeck[i])[0]++;
				
				//recursive call
				runAlgorithm(newTurnsLeft , countInHand , cardsInDeck , idxInDeck + drawFromDeck , newScore);
				
				// undo adding to the deck
				for (int i = idxInDeck; i < idxInDeck + drawFromDeck && i < cardsInDeck.length; i++)
					countInHand.get(cardsInDeck[i])[0]--;
				
				// undo playing it
				countInHand.get(card)[0]++;
			}
		
		// limit one second per update
		long currentTime = System.currentTimeMillis();
		if (currentTime - updateTime > 1000)
		{
			// force break
			maxPossibleScore = bestScore;
			
		}
	}
	
	private static int readCard(String line)
	{
		//System.out.println(line);
		String lineT[] = tokenize(line);
		int c = Integer.parseInt(lineT[0]);
		int s = Integer.parseInt(lineT[1]);
		int t = Integer.parseInt(lineT[2]);
		
		int out = (99-c) * 10000 + (99-s) * 100 + (99-t);
		assert getC(out) == c;
		assert getS(out) == s;
		assert getT(out) == t;
		return out;
	}
	
	
	
	public static String[] tokenize(String input)
	{
		StringTokenizer st = new StringTokenizer(input);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	public static String[] tokenize(String input, String sep)
	{
		StringTokenizer st = new StringTokenizer(input , sep);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	
}

