import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class Q1 {

	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		int numTests = s.nextInt();
		for (int test = 0; test < numTests; test++)
		{
			System.out.println("Case #" + (test+1) + ": " + getResult(s));
		}
	}
	
	private static String getResult(Scanner s)
	{
		int numNodes = s.nextInt();
		List<GraphNode> nodes = new ArrayList<GraphNode>(numNodes);
		for (int i = 0; i < numNodes; i++)
		{
			nodes.add(new GraphNode());
		}
		for (int i = 0; i < numNodes; i++)
		{
			int numChildren = s.nextInt();
			for (int j = 0; j < numChildren; j++)
			{
				int child = s.nextInt();
				nodes.get(child-1).childNodes.add(nodes.get(i));
			}
		}
		for (GraphNode node : nodes)
		{
			if (node.childNodes.size() > 1 && node.hasDiamond())
			{
				return "Yes";
			}
		}
		return "No";
	}
	
	public static class GraphNode
	{
		public List<GraphNode> childNodes = new LinkedList<GraphNode>();
		
		public boolean hasDiamond()
		{
			List<GraphNode> foundSoFar = new LinkedList<GraphNode>();
			Set<GraphNode> fastLookup = new HashSet<GraphNode>();
			foundSoFar.add(this);
			fastLookup.add(this);
			while (foundSoFar.size() > 0)
			{
				GraphNode node = foundSoFar.remove(0);
				for (GraphNode child : node.childNodes)
				{
					if (fastLookup.contains(child))
						return true;
					foundSoFar.add(child);
					fastLookup.add(child);
				}
			}
			return false;
		}
	}
}
