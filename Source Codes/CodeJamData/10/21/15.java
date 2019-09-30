import java.util.*;
public class A
{
	public static void main(String[] args)
	{
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	sc.nextLine();
	for(int c = 1; c <= cases; c++)
	{
		int numBase = sc.nextInt();
		int numNew = sc.nextInt();
		TreeNode root = new TreeNode();
		for(int i = 0; i < numBase; i++)
		{
			String s = sc.next();
			String[] parts = s.split("/");
			TreeNode cd = root;
			for(int j = 1; j < parts.length; j++)
			{
				if(cd.children.containsKey(parts[j]))
					cd = cd.children.get(parts[j]);
				else
				{
					TreeNode nw = new TreeNode();
					cd.children.put(parts[j], nw);
					cd = nw;
				}
			}
		}
		
		int count = 0;
		
		for(int i = 0; i < numNew; i++)
		{
			String s = sc.next();
			
			String[] parts = s.split("/");
			
			TreeNode cd = root;
			for(int j = 1; j < parts.length; j++)
			{
				if(cd.children.containsKey(parts[j]))
					cd = cd.children.get(parts[j]);
				else
				{
					TreeNode nw = new TreeNode();
					cd.children.put(parts[j], nw);
					
					cd = nw;
					count++;
				}
			}
		}
		
		System.out.println("Case #" + c + ": " + count);
	}
	}
}

class TreeNode
{
	HashMap<String, TreeNode> children = new HashMap<String, TreeNode>();
}