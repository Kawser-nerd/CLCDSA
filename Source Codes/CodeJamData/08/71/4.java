import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class MixingBowls
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
		Map<String, Mixture> mixes = new HashMap<String, Mixture>();
		int numMixes = in.nextInt();
		Mixture mainMix = null;
		for (int i = 0; i < numMixes; i++)
		{
			Mixture mix = new Mixture(in);
			mixes.put(mix.getName(), mix);
			if (i == 0)
				mainMix = mix;
		}

		System.out.println("Case #" + caseNum + ": " + mainMix.getCost(mixes));
	}

	private static class Mixture
	{
		private String name;
		private String[] depends;

		Mixture(Scanner in)
		{
			name = in.next();
			String[] dependsTemp = new String[in.nextInt()];
			int numReal = 0;
			for (int i = 0; i < dependsTemp.length; i++)
			{
				dependsTemp[i] = in.next();
				if (Character.isUpperCase(dependsTemp[i].charAt(0)))
					numReal++;
			}
			depends = new String[numReal];
			int index = 0;
			for (int i = 0; i < dependsTemp.length; i++)
			{
				if (Character.isUpperCase(dependsTemp[i].charAt(0)))
					depends[index++] = dependsTemp[i];
			}
		}

		public int getCost(Map<String, Mixture> map)
		{
			if (depends.length == 0)
				return 1;

			int[] costs = new int[depends.length];

			for (int i = 0; i < costs.length; i++)
			{
				String string = depends[i];
				if (Character.isLowerCase(string.charAt(0)))
					costs[i] = 0;
				else
					costs[i] = map.get(string).getCost(map);
			}

			Arrays.sort(costs);

			int maxBowls = -1;

			for (int i = 0; i < costs.length; i++)
			{
				int thisCost = costs[i] + costs.length - 1 - i;
				if (thisCost > maxBowls)
					maxBowls = thisCost;
			}

			return Math.max(maxBowls, costs.length + 1);
//			if (maxBowls >= costs.length + 1)
//				return maxBowls;
//
//			if (maxBowls == 0)
//				return 2;
//			return maxBowls + 1;
		}

		private String getName()
		{
			return name;
		}
	}
}
