import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
public class FullBinaryTree {
	public final static String INPUT_FILE_NAME = "B-large(1).in";
	public final static String OUTPUT_FILE_NAME = "FullBinaryTree.out";
	public static void main(String[] args) {
		try (Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new FileWriter(
						OUTPUT_FILE_NAME))) {
			int numT = in.nextInt();
			for (int t = 1; t <= numT; t++) {
				System.out.println("Case " + t);
				int numNode = in.nextInt();
				ArrayList<Node> nodes = new ArrayList<>();
				for(int i = 0; i < numNode; i ++)
				{
					nodes.add(new Node());
				}
				for (int i = 0; i < numNode-1; i++)
				{
					int a = in.nextInt()-1;
					int b = in.nextInt()-1;
					nodes.get(a).addChild(nodes.get(b));
					nodes.get(b).addChild(nodes.get(a));
				}
				int best = 0;
				for(Node n : nodes)
				{
					best = Math.max(best, n.maxChildren(null));
				}
				int res = numNode - best;
				out.println("Case #"+t+": " + res);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static class Node
	{
		ArrayList<Node> children;
		
		public Node()
		{
			children = new ArrayList<>();
		}
		
		public void addChild(Node n)
		{
			children.add(n);
		}
		
		public int maxChildren(Node parent)
		{
			int best = 0;
			int best2 = 0;
			for(Node n : children)
			{
				if(n != parent)
				{
					int nv = n.maxChildren(this);
					if(nv > best)
					{
						best2 = best;
						best = nv;
					}
					else if(nv > best2)
					{
						best2 = nv;
					}
				}
			}
			if(best2 == 0)return 1;
			return best + best2 + 1;
		}
	}
}
