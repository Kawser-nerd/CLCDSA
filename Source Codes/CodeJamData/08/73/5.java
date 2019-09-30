import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class TestPassingProbability
{

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for (int i = 0; i < numCases; i++)
		{
			doCase(in, i + 1);
		}
	}

	private static void doCase(Scanner in, int caseNum)
	{
		int M = in.nextInt();
		int Q = in.nextInt();
		double[][] probs = new double[Q][4];
		for (int i = 0; i < probs.length; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				probs[i][j] = in.nextDouble();
			}
		}
		ArrayList<Double> totalProbs = new ArrayList<Double>(1 << (2 * Q));
		makeProbs(probs, 1, 0, totalProbs);
		Collections.sort(totalProbs);
		double totalProb = 0;
		int size = totalProbs.size();
		for (int i = 0; i < M; i++)
		{
			if (i >= size)
				break;
			totalProb += totalProbs.get(size - 1 - i);
		}
		System.out.println("Case #" + caseNum + ": " + totalProb);
	}

	private static void makeProbs(double[][] probs, double probToHere, int i,
			ArrayList<Double> totalProbs)
	{
		if (i == probs.length)
			totalProbs.add(probToHere);
		else
			for (int j = 0; j < 4; j++)
				makeProbs(probs, probs[i][j] * probToHere, i + 1, totalProbs);
	}
}
