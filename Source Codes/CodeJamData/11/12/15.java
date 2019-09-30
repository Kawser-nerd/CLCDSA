import java.util.*;
import java.io.*;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Book-Bambuk
 */
public class Solution {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader in = new BufferedReader(new FileReader("c:\\codejam\\cj2011_r1a_b\\input.txt"));
        PrintWriter out = new PrintWriter("c:\\codejam\\cj2011_r1a_b\\output.txt");
        int t = Integer.parseInt(in.readLine());
        int c,  n ,m;
        Map<Integer,List<String>> d;
        List<String> l;

        for (int i = 0; i < t; i++) {
            String data = in.readLine();
            StringTokenizer st = new StringTokenizer(data);
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            
            d = new HashMap<Integer, List<String>>();
            dm = new HashMap<String, Integer>();
            for (int j =1; j<11; j++)
            {
                d.put(j, new ArrayList<String>());

            }
            for (int j = 0; j < n; j++) {
                data = in.readLine();
                d.get(data.length()).add(data);
                dm.put(data,j);
            }
            l = new ArrayList<String>();
            for (int j = 0; j < m; j++) {
                data = in.readLine();
                l.add(data);
            }
            String ans = solve(n, m, d, l);
            out.println("Case #" + String.valueOf(i + 1) + ": " + ans);

        }
        in.close();
        out.close();
    }

    private static String maxString = null;
    private static Integer max = null;
    private static Integer maxNum = null;
    private static Map<String,Integer> dm = null;

    private static String solve(int n, int m, Map<Integer,List<String>> d, List<String> l) {
        StringBuffer result = new StringBuffer();
        for (int i = 0; i<m; i++)
        {
           max = 0;
           maxNum = n+1;
           StringBuffer pattern = new StringBuffer();
           for (int j = 1; j<11; j++)
           {
               pattern.append("_");
               if (d.get(j) != null && d.get(j).size()>0)
               {
                    find(d.get(j),l.get(i),0,pattern.toString(), 0);
                    if (maxString == null)
                    {
                         max = 0;
                         maxString = d.get(j).get(0);
                         maxNum = dm.get(maxString);

                    }
               }
           }
           if (result.length()>0)
           {
               result.append(" ");
           }
           result.append(maxString);
        }
        return result.toString();
    }

    private static void find(List<String> dic, String li, int p, String pattern, int deapth) {
       if (dic.size() == 1)
       {
           if (deapth>max)
           {
               max = deapth;
               maxString = dic.get(0);
               maxNum = dm.get(maxString);
           }
           else
           {
                if(deapth == max)
                {
                    int newNum = dm.get(dic.get(0));
                    if (maxNum > newNum)
                    {
                         max = deapth;
                         maxString = dic.get(0);
                         maxNum = newNum;
                    }
                }
           }
       }
       else
       {
           Map<String, List<String>> subsets;
           StringBuffer pa, pa1;
           pa = new StringBuffer(pattern);
           for (int q = p; q<26; q++)
           {
               subsets = new HashMap<String, List<String>>();
                pa1 = new StringBuffer(pa);
               char c = li.charAt(q);
               for (String word : dic)
               {
                   pa1 = new StringBuffer(pa);
                   
                   for (int i =0; i<word.length(); i++)
                   {
                       if (word.charAt(i) == c)
                       {
                           pa1.setCharAt(i, c);
                       }
                   }

                   if (subsets.get(pa1.toString())==null)
                   {
                       subsets.put(pa1.toString(), new ArrayList<String>());
                   }
                   subsets.get(pa1.toString()).add(word);
               }
               if (subsets.keySet().size()>1)
               {
                   for (String key : subsets.keySet())
                   {
                       int dd = 0;
                       if (key.indexOf(c)<0)
                       {
                         dd = 1;
                       }
                      find(subsets.get(key), li, q+1, key, deapth + dd);
                   }
                   break;
               }
                 else
                   {
                    pa = new StringBuffer((String)subsets.keySet().toArray()[0]);
                    }
              
           }
        }
    }

}
